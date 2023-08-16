// list.c 

#include <func.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

int main(int argc, char* argv[]) {

    int i = 0;
    if (argc > 1)
        i = 1;

    DIR* pdir;

    for (; i < argc; ++i){
        if (i == 0) {
            puts(".");
            pdir = opendir(".");
        } else {
            puts(argv[i]);
            pdir = opendir(argv[i]);
        }

        ERROR_CHECK(pdir, NULL, "opendir");

        struct dirent* pdirent;
        errno = 0;
        while (1) {
            pdirent = readdir(pdir);
            if (pdirent == NULL)
                break;

            printf("%s  ", pdirent->d_name);
        }
        printf("\n\n");

        closedir(pdir);

        if (errno) {
            perror("readdir");
            exit(1);
        }
    }

    return 0;    
}
