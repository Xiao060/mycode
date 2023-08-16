#include <func.h>

int main(int argc, char* argv[]) {
    ARGS_CHECK(argc, 2);

    int fd = open(argv[1], O_RDWR);
    ERROR_CHECK(fd, -1, "open");


    char buf[1024];
    int ret = read(fd, buf, sizeof(buf));
    ERROR_CHECK(ret, -1, "read");

    puts(buf);

    off_t file_size = lseek(fd, 0, SEEK_END);
    ERROR_CHECK(file_size, -1, "lseek");
    /* int ret = ftruncate(fd, file_size); */
    /* ERROR_CHECK(ret, -1, "ftruncate"); */

    char* p = (char*) mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    ERROR_CHECK(p, MAP_FAILED, "mmap");

    for (int i=0; i < file_size; ++i) {
        if (islower(p[i]))
            p[i] = toupper(p[i]);

        if (ispunct(p[i]))
            p[i] = ' ';
    }

    munmap(p, file_size);
    close(fd);

    return 0;
}
