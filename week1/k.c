#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100
#define MAX_LEN 200

typedef struct 
{
    int stt;
    char name[MAX_LEN];
    double price;
} Product;

void read_file(FILE *fin){
    char buff[MAX_LEN];
    int i=0;
    //vòng lặp qua từng dòng
    while(fgets(buff,MAX_LEN,fin)!=NULL){
        Product pr;
        //định dạng dữ liệu trong dòng
        sscanf(buff,"%d%s%lf\n",
           &pr.stt,
           pr.name,
           &pr.price
           );
        printf("%d  %s  %.2lf\n",pr.stt,pr.name,pr.price);
}}

int main(int argc,char *argv[]){
    if(argc!=2){
        printf("usage:%s <file_name> \n",argv[0]);
        return 1;
    }
    char *file_name=argv[1];
    
    FILE *p=fopen(file_name,"r");
 
    if(p==NULL){
        printf("Error: can not open file %s\n",file_name);
        return 1;
    }
    
  
    read_file(p);
    fclose(p);


   
    return 0;



}


