// tree.c 

#include <func.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

void dfs_print(const char* path, int width);

int directories = 0, files = 0;

int main(int argc, char* argv[]) {
    ARGS_CHECK(argc, 2);

    puts(argv[1]);

    dfs_print(argv[1], 4);

    printf("\n%d directories, %d files\n", directories, files);

    return 0;
}


void dfs_print(const char* path, int width) {

    DIR* pdir = opendir(path);
    struct dirent* pdirent;
    while (pdirent = readdir(pdir)) {

        if (strcmp(pdirent->d_name, ".") == 0 || strcmp(pdirent->d_name, "..") == 0) 
            continue;

        for (int i=0; i<width; ++i)
            printf(" ");
        printf("%s\n", pdirent->d_name);

        if (pdirent->d_type != DT_DIR)
            files++;
        else {
            char s[200];
            getcwd(s, 200);
            strcat(s, "/"); 
            strcat(s, pdirent->d_name);
            printf("%s\n", s);
            dfs_print(s, width + 4);
            directories++;
        } 
    }
    closedir(pdir);
    return;
}




