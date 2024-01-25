#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100
#define MAX_LEN 200
//sao chép thông tin sv ra file mới them điểm vào phía sau
//tạo cấu trúc sinh viên 
typedef struct 
{
    int stt;
    int MSSV;
    char name[MAX_SIZE];
    char phone[MAX_SIZE];
    float score;
} Student;
//tạ hàm đọc dữ liệu cho sinh viên từ file đầu vào và từ 1 mảng điểm cho trước
void read_file(FILE *fin,FILE *fout,float *arr,int size){
    char buff[MAX_LEN];
    int i=0;
    //vòng lặp qua từng dòng
    while(fgets(buff,MAX_LEN,fin)!=NULL){
        Student student;
        //định dạng dữ liệu trong dòng
        sscanf(buff,"%d %d %s %s\n",
            &student.stt,
            &student.MSSV,
            student.name,
            student.phone);
        student.score=arr[i];
        i++;
        //ghi vào file mới với điểm
        fprintf(fout,"%d %d %s %s %.2f\n",
            student.stt,
            student.MSSV,
            student.name,
            student.phone,
            student.score);
}}

int main(int argc,char *argv[]){
    if(argc<4){
        printf("usage:%s <file_name> <d_file> <score>\n",argv[0]);
        return 1;
    }
    char *file_name=argv[1];
    char *d_file=argv[2];
    FILE *p=fopen(file_name,"r");
    FILE *p_1=fopen(d_file,"w");
    if(p==NULL){
        printf("Error: can not open file %s\n",file_name);
        return 1;
    }
    if(p_1==NULL){
        printf("Error: can not open file %s\n",d_file);
        return 1;
    }
    float *arr=(float *)malloc((argc-4)*sizeof(int));
    for(int i=3;i<argc;i++){
        arr[i-3]=atof(argv[i]);
    }
    read_file(p,p_1,arr,argc-3);
    fclose(p);
    fclose(p_1);
    free(arr);
    printf("file is done successfully.\n");
    return 0;



}


