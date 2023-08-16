#include <func.h>

typedef struct student {
    int num;
    char name[1024];
    float score;
} Student;

void print(const Student* s, int n);

int main(int argc, char* argv[]) {
    ARGS_CHECK(argc, 2);

    Student stu1[3] = { {1, "xiao ming", 80.7}, 
                        {2, "xiao hong", 97.3},
                        {3, "xiao gang", 72.6}};

    int fd = open(argv[1], O_RDWR | O_CREAT, 0666);
    ERROR_CHECK(fd, -1, "open");

    ssize_t ret1 = write(fd, stu1, sizeof(stu1));
    ERROR_CHECK(ret1, -1, "write");

    off_t ret2 = lseek(fd, 0, SEEK_SET);
    ERROR_CHECK(ret2, -1, "lseek");

    Student stu2[3];
    ret1 = read(fd, stu2, sizeof(stu2));
    ERROR_CHECK(ret1, -1, "read");

    print(stu2, SIZE(stu2));
    close(fd);

    return 0;
}

void print(const Student* s, int n) {
    for (int i = 0; i < n; ++i) 
        printf("num: %d\nname: %s\nscore: %.2f\n\n", 
                s[i].num, s[i].name, s[i].score); 
}
