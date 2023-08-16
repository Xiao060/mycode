#include <func.h>

int main(void) {
    int fd = open("file", O_RDWR | O_TRUNC | O_CREAT, 0666);
    ERROR_CHECK(fd, -1, "open");

    pid_t pid = fork();
    if (pid == 0) {
        printf("I am a child process\n");
        write(fd, "hello", 5);
    } else {
        printf("I am parent process\n");
        sleep(1);
        write(fd, " world!", 7);
        printf("parent writing end!\n");
    }

    return 0;
}
