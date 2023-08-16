#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char* argv[]){
    if (argc != 2){
        printf("Error: the value of argc must be two!\n");
        exit(1);
    }

    int chars, words, lines;
    chars = words = lines = 0;

    FILE* fp = fopen(argv[1], "r");

    bool space = true;
    char c;
    c = fgetc(fp);
    while (c != EOF){
        chars++;
        if (c == ' ' || c == '\t' || c == '\v' || c == '\f'){
            space = true;
        } else if (c == '\n'){
            space = true;
            lines++;
        }
        else{
            if (space == true){
                space = false;
                words++;
            }
        } 
        c = fgetc(fp);
    }
    printf("chars: %d \nwords: %d \nlines: %d\n", chars, words, lines);

    fclose(fp);
    return 0;
}
