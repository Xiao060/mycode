// tree.c 

#include <func.h>

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
    int ret = chdir(path);
    ERROR_CHECK(ret, -1, "chdir");

    DIR* pdir = opendir(".");
    ERROR_CHECK(pdir, NULL, "opendir");

    struct dirent* pdirent;
    while ((pdirent = readdir(pdir))) {

        int cmp1 = strcmp(pdirent->d_name, ".");
        int cmp2 = strcmp(pdirent->d_name, "..");
        if (!cmp1 || !cmp2) 
            continue;

        for (int i=0; i<width-3; ++i){
            if (i % 4 == 0)
                printf("|");
            else 
                printf(" ");
        }

        printf("---");
        printf("%s\n", pdirent->d_name);

        if (pdirent->d_type != DT_DIR)
            files++;
        else {
            dfs_print(pdirent->d_name, width + 4);
            directories++;
        } 
    }
    closedir(pdir);

    ret = chdir("..");
    ERROR_CHECK(ret, -1, "chdir");
}




