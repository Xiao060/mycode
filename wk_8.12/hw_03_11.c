#include <func.h>
#define NUMS 10000000

#define turn p[1]
#define want_to_enter (p+2)

void dekker(int me, int other, int* p);

int main(int argc, char* argv[]) {
    
    key_t key = 0x5678;

    int shmid = shmget(key, 4096, IPC_CREAT | 0600);
    int* p = (int*) shmat(shmid, NULL, 0);

    // (p+2)[0] 即 p[2], (p+2)[1] 即 p[3]
    want_to_enter[0] = 0;
    want_to_enter[1] = 0;

    // p[1]
    turn = 0;

    // value
    p[0] = 0;


    if (fork()) {
        for (int i=0; i < NUMS; ++i) {
            dekker(0, 1, p);
        }

        wait(NULL);

        printf("p[0] = %d\n", p[0]);
    } else {
        for (int i=0; i < NUMS; ++i) {
            dekker(1, 0, p);
        }
    }

    return 0;
}



void dekker(int me, int other, int* p) {
    want_to_enter[me] = 1;

    while (want_to_enter[other]) {
        // turn != me
        if (turn != me) {
            want_to_enter[me] = 0;

            while (turn != me) ;

            want_to_enter[me] = 1;
        }
    }

    p[0]++;

    turn = other;    
    want_to_enter[me] = 0;
}












