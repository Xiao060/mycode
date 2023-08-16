#include <func.h>

#define NUMS 10000000

int main(int argc, char* argv[]) {

    key_t key = 0x2525;

    // 分配用于共享的物理内存
    int shmid = shmget(key, 4096, IPC_CREAT | 0600);

    // 分配虚拟内存, 第2个参数为NULL代表由os分配
    // 分配完成会将对应区域初始化为0 
    int* shmadd = (int*) shmat(shmid, NULL, 0);

    shmadd[0] = 0;
    
    if (fork()) {
        for (int i = 0; i < NUMS; ++i) {
            shmadd[0]++;
        }

        wait(NULL);

        printf("shmadd[0] = %d\n", shmadd[0]);
    } else {
        for (int i = 0; i < NUMS; ++i) {
            shmadd[0]++;
        }
    }

    return 0;
}
