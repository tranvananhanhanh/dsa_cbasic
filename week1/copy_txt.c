#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
enum{SUCCESS,FAIL};
void readandwrite(FILE *fin, FILE *fout){
    int c;
    while((c=fgetc(fin))!=EOF){
        c=toupper(c);
        fputc(c,fout);
        putchar(c);
    }
}
main(void){
    FILE *fptr1,*fptr2;
    char fn1[]="file.txt";
    char fn2[]="cfile.txt";
    int reval=SUCCESS;
    if((fptr1=fopen(fn1,"r"))==NULL){
        reval=FAIL;
    }
    if((fptr2=fopen(fn2,"w"))==NULL){
        reval=FAIL;
    }
    else{
        readandwrite(fptr1,fptr2);
        fclose(fptr1);
        fclose(fptr2);
    }
}