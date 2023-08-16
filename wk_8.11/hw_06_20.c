// 可执行程序 2.1 
#include <func.h>

int main(int argc, char* argv[]) {

    printf("process 2 start!\n\n");
    
    DIR* pdir = opendir(".");
    ERROR_CHECK(pdir, NULL, "opendir");

    struct dirent* pdirent;
    while (1) {
        pdirent = readdir(pdir);

        if (pdirent == NULL) {
            break;
        }

        printf("%s    ", pdirent->d_name);
    }
    printf("\n\n");

    printf("process 2 end!\n");

    return 0;
}
