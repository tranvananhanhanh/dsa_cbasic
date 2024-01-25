#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
    if(argc!=2){
        printf("Usage: %s <source_file> \n", argv[0]);
        return 1;
    }
    char *sourcefile=argv[1];
    FILE *p=fopen(sourcefile,"r+");
    if (p == NULL) {
        printf("Error: Cannot open source file '%s'\n", sourcefile);
        return 2;
    }
    char c;
    //sử dụng vòng lặp để đọc từng kí tự
    while ((c=fgetc(p))!=EOF){
        c=toupper(c);
        //di chuyển con trỏ đến kí tự tiếp theo
        fseek(p,-1,SEEK_CUR);
        fputc(c, p);

    }
    fclose(p);
    printf("file conservation successfful.\n");
    return 0;
}