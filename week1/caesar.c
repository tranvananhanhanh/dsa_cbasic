#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main(int argc,char *argv[]){
    if(argc!=4){
        printf("Usage: %s <source_file> <offfset> <destination_file> \n", argv[0]);
        return 1;
    }
    char *sf=argv[1];
    int of=atoi(argv[2]);
    char *df=argv[3];
    FILE *p_1=fopen(sf,"r");
    FILE *p_2=fopen(df,"w");
    if (p_1 == NULL) {
        printf("Error: Cannot open source file '%s'\n",sf);
        return 2;
    }
    if (p_2 == NULL) {
        printf("Error: Cannot open destination file '%s'\n", df);
        return 2;
    }
    char c;
    while ((c=fgetc(p_1))!=EOF)
    {   if (isalpha(c)) {
            if (isupper(c)) {
                c = (c - 'A' + of) % 26 + 'A'; // Dịch chuyển ký tự hoa
            } else {
                c = (c - 'a' + of) % 26 + 'a'; // Dịch chuyển ký tự thường
            }
        }
        else {
            c=c+of;
        }
        
        fputc(c,p_2);
    }
    fclose(p_1);
    fclose(p_2);
    return 0;
}