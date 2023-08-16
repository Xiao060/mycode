// tree.c 

#include <func.h>

// 传入参数
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
    ERROR_CHECK(pdir, NULL, "opendir");

    errno = 0;
    struct dirent* pdirent;
    while ((pdirent = readdir(pdir))) {
        // 忽略 . / .. / 隐藏文件
        char* name = pdirent->d_name;
        if (name[0] == '.')
            continue;

        // 缩进
        for (int i=0; i<width; ++i)
            printf(" ");
        puts(name);


        if (pdirent->d_type != DT_DIR)
            files++;
        else {
            char subpath[1024];
            sprintf(subpath, "%s/%s", path, name);
            dfs_print(subpath, width + 4);
            directories++;
        } 
    }

    if (errno)
        perror("readdir:");

    closedir(pdir);
}




