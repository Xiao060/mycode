#include <func.h>

typedef struct student {
    int num;
    char name[1024];
    float score;
} Student;

void print(const Student* s, int n);

int main(int argc, char* argv[]) {
    ARGS_CHECK(argc, 2);

    int fd = open(argv[1], O_RDWR);
    ERROR_CHECK(fd, -1, "open");

    Student stu[3];
    ssize_t ret = read(fd, stu, sizeof(stu));
    ERROR_CHECK(ret, -1, "read");

    print(stu, SIZE(stu));
    close(fd);

    return 0;
}


void print(const Student* s, int n) {
    for (int i = 0; i < n; ++i) 
        printf("num: %d\nname: %s\nscore: %.2f\n\n", 
                s[i].num, s[i].name, s[i].score); 
}
