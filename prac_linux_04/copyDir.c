#include <func.h>

void copyFile(const char* src, const char* dst);
void copyDir(const char* src, const char* dst);

int main(int argc, char* argv[]) {
    ARGS_CHECK(argc, 3);
    copyDir(argv[1], argv[2]);
    return 0;
}

void copyFile(const char* src, const char* dst) {
    FILE* fp = fopen(src, "rb");
    ERROR_CHECK(fp, NULL, "fopen");

    fseek(fp, 0, SEEK_END);
    long int file_size = ftell(fp);
    
    char* file_char = malloc(file_size+1);
    ERROR_CHECK(file_char, NULL, "malloc");

    rewind(fp);
    int read_size = fread(file_char, 1, file_size+1, fp);

    fclose(fp);

    
    fp = fopen(dst, "wb");
    ERROR_CHECK(fp, NULL, "fopen");

    fwrite(file_char, 1, read_size, fp);

    fclose(fp);

    free(file_char);
}

void copyDir(const char* src, const char* dst) {
    int ret = mkdir(dst, 0777);
    ERROR_CHECK(ret, -1, "mkdir");


    DIR* pdir = opendir(src);
    ERROR_CHECK(pdir, NULL, "opendir");

    errno = 0;
    struct dirent* pdirent;
    while ((pdirent = readdir(pdir))) {

        char* name = pdirent->d_name;
        if (name[0] == '.')
            continue;

        char src_subpath[1024];
        sprintf(src_subpath, "%s/%s", src, name);

        char dst_subpath[1024];
        sprintf(dst_subpath, "%s/%s", dst, name);

        if (pdirent->d_type != DT_DIR) {
            copyFile(src_subpath, dst_subpath);
        } else {
            copyDir(src_subpath, dst_subpath);
        }
    }

    if (errno)
        perror("readdir");

    closedir(pdir);
}





