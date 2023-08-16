#include <func.h>

int main(void) {
    DIR* pdir = opendir(".");
    printf("%p\n", pdir);

    /* printf("%s\n", (*pdir).d_name); */

    long loc = telldir(pdir);
    printf("%ld\n", loc);


    struct dirent* pdirent;
    while (pdirent = readdir(pdir)) {
        printf("%p  %s\n", pdir, pdirent->d_name);
    }

    seekdir(pdir, 0);

    while (pdirent = readdir(pdir)) {
        printf("%p  %s\n", pdir, pdirent->d_name);
    }

    return 0;
}
