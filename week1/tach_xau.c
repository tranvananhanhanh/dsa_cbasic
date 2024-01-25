#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 100
//sử dụng hàm strok để tách xâu, các từ tách ra được lưu vào 1 con trỏ 
int main(void){
    char str[SIZE +1];
    fgets(str,sizeof(str),stdin);
    char *token=strtok(str," ");
    //tạo vòng lặp qua tất cả giá trị token để truy cập vào các giá trị token ta sẽ truyền null vào giá trị đầu mảng 
    while(token!=NULL){
        printf("%s\n",token);
        token=strtok(NULL," ");
    }
    return 0;
}