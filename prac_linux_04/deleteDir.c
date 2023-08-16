#include <func.h>
#include <sys/types.h>
#include <dirent.h>

void deleteDir(const char* path);

int main(int argc, char* argv[]) {
    ARGS_CHECK(argc, 2);

    deleteDir(argv[1]);

    return 0;
}


void deleteDir(const char* path){
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

        if (pdirent->d_type != DT_DIR) {
            int ret = unlink(pdirent->d_name);
            ERROR_CHECK(ret, -1, "unlink");
        }
        else {
            deleteDir(pdirent->d_name);
        }
    }

    ret = chdir("..");
    ERROR_CHECK(ret, -1, "chdir");

    ret = rmdir(path);
    ERROR_CHECK(ret, -1, "rmdir");
    
    closedir(pdir);
}
