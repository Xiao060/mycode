#include <func.h>
#define NUMS 10000000

void dekker(int me, int other, int* arr);

int main(int argc, char* argv[]) {
    
    key_t key = 0x5678;

    int shmid = shmget(key, 4096, IPC_CREAT | 0600);
    int* p = (int*) shmat(shmid, NULL, 0);

    // want_to_enter[0], want_to_enter[1]
    p[0] = 0;
    p[1] = 0;

    // turn
    p[2] = 0;

    // value
    p[3] = 0;


    if (fork()) {
        for (int i=0; i < NUMS; ++i) {
            dekker(0, 1, p);
        }

        wait(NULL);

        printf("p[3] = %d\n", p[3]);
    } else {
        for (int i=0; i < NUMS; ++i) {
            dekker(1, 0, p);
        }
    }

    return 0;
}



void dekker(int me, int other, int* arr) {
    arr[me] = 1;

    while (arr[other]) {
        // turn != me
        if (arr[2] != me) {
            arr[me] = 0;

            while (arr[2] != me) ;

            arr[me] = 1;
        }
    }

    arr[3]++;

    // turn = other
    arr[2] = other;    
    arr[me] = 0;
}












