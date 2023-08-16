#include <func.h>

typedef struct student {
    int num;
    char name[1024];
    float score;
} Student;


int main(int argc, char* argv[]) {
    ARGS_CHECK(argc, 2);

    Student stu[3] = { {1, "xiao ming", 80.7}, 
                       {2, "xiao hong", 97.3},
                       {3, "xiao gang", 72.6}};

    int fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0666);
    ERROR_CHECK(fd, -1, "open");

    ssize_t ret = write(fd, stu, sizeof(stu));
    ERROR_CHECK(ret, -1, "write");

    close(fd);

    return 0;
}
