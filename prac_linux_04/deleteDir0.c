#include <func.h>

void deleteDir(const char* path);

int main(int argc, char* argv[]) {
    ARGS_CHECK(argc, 2);

    deleteDir(argv[1]);

    return 0;
}


void deleteDir(const char* path){

    DIR* pdir = opendir(path);
    ERROR_CHECK(pdir, NULL, "opendir");

    errno = 0;
    struct dirent* pdirent;
    while ((pdirent = readdir(pdir))) {

        char* name = pdirent->d_name;
        if (!strcmp(name, ".") || !strcmp(name, ".."))
            continue;

        char subpath[1024];
        sprintf(subpath, "%s/%s", path, name);

        if (pdirent->d_type != DT_DIR) {
            int ret = unlink(subpath);
            ERROR_CHECK(ret, -1, "unlink");
        } else {
            deleteDir(subpath);
        }
    }

    if (errno)
        perror("readdir");

    int ret = rmdir(path);
    ERROR_CHECK(ret, -1, "rmdir");

    closedir(pdir);
}
