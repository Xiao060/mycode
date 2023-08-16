#include <func.h>

typedef struct student {
    int num;
    char name[1024];
    float score;
} Student;



int main(void) {

    int a[5] = {1, 2, 3, 4, 5};

    printf("sizeof(int): %ld\n", sizeof(int));
    printf("sizeof(a): %ld\n", sizeof(a));


    Student stu[3] = { {1, "xiao ming", 80.7}, 
                   {2, "xiao hong", 97.3},
                   {3, "xiao gang", 73.6}};
    printf("sizeof(Student): %ld\n", sizeof(Student));
    printf("sizeof(stu): %ld\n", sizeof(stu));
}
