#include <func.h>

void* threadFunc(void* arg);

int main(int argc, char* argv[]) {
    ARGS_CHECK(argc, 2);

    int fd = open(argv[1], O_RDWR);
    ERROR_CHECK(fd, -1, "open");

    pthread_t tid;
    pthread_create(&tid, NULL, threadFunc, &fd);
     
    char buf[4096] = {0};
    ssize_t sret = read(fd, buf, 5);
    printf("sret = %ld, buf = %s\n", sret, buf);
    
    sleep(5);

    close(fd);

    /* sleep(10); */

    pthread_join(tid, NULL);

    return 0;
}


void* threadFunc(void* arg) {
    sleep(3);

    int* pfd = (int*) arg;

    char buf[4096];
    while (1) {
        memset(buf, 0, sizeof(buf));
        ssize_t sret = read(*pfd, buf, sizeof(buf));
        /* if (sret == -1) { */
        /*     printf("errno = %d", errno); */
        /* } */
        ERROR_CHECK(sret, -1, "child read");

        // 文件未读完
        if (sret != 0) {
            printf("sret = %ld, buf = %s\n", sret, buf);
        }
    }

    return NULL;
}
