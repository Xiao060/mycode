#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

  if (argc < 3){
    printf("Error: need three arguments!\n");
    exit(1);
  }

  FILE* fp1 = fopen(argv[1], "rb");
  if (!fp1){
    perror(argv[1]);
    exit(1);
  }

  fseek(fp1, 0, SEEK_END);

  long file_size = ftell(fp1);

  // 多申请一个空间用于放置空字符
  char* file_char = malloc(file_size + 1);
  if (!file_char){
    perror("file_char");
    fclose(fp1);
    exit(1);
  }  

  rewind(fp1);
  int read_size = fread(file_char, 1, file_size, fp1);
  fclose(fp1);

  FILE* fp2 = fopen(argv[2], "wb");
  
  fwrite(file_char, 1, file_size, fp2);

  fclose(fp2);

}
