#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define PAGE_SIZE 20
#define MAX_LEN 81
void display(FILE *file){
    int count=0;
    char line[MAX_LEN];
    while(fgets(line,sizeof(line),file)!=NULL){
        printf("%s",line);
        count++;
        if(count==PAGE_SIZE){
            printf("press any key to countinue");
            getchar();
            count=0;
        }
    }
}

int main(int argc,char *argv[]){
    if(argc<2||argc>3){
        printf("Usage: %s <file_name> \n: display all", argv[0]);
        printf("Usage: %s <file_name> -p: display by pages \n", argv[0]);
        return 1;
    }
    char *file_name=argv[1];
    FILE *p=fopen(file_name,"r");
    if(p==NULL){
        printf("Error: Cannot open file %s\n", file_name);
        return 2;
    }
    if(argc==2){
        int c;
        while((c=fgetc(p))!=EOF){
            putchar(c);
        }
        return 0;
    }
    if(argc==3){
        display(p);
        return 0;

    }
    fclose(p);
}