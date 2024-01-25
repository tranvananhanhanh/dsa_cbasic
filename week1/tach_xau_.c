#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 100
//Nếu offset < 0 hoặc offset >= độ dài của xâu hoặc number <= 0 thì hiển thị ra màn hình "Error".

// Xây dựng và chạy minh họa (demo) hàm sau
//char* subStr(char* s1, int offset, int number)
//Hàm tách xâu con từ xâu s1 bắt đầu từ ký tự tại chỉ số offset (tính từ 0) và có độ dài number ký tự.
//Chú ý kiểm tra tính hợp lệ của các đối số. Trong trường hợp giá trị number lớn hơn độ dài phần còn lại của xâu s1 tính từ vị trí offset, trả về xâu con là phần còn lại của s1 tính từ vị trí offset.
char* subStr(char *s1,int offset,int number){
    int x=strlen(s1);
    char *result;
    result = (char*)malloc((number - offset+ 1) * sizeof(char));
    if(result==NULL){
        return NULL;
    }
    int k=0;
    
    for(int i=offset;i<=number;i++){
        result[k]=s1[i];
        k++;
        
    }
    return result;
    }

int main(){
    char str1[MAX_LEN];
    fgets(str1,MAX_LEN,stdin);
    int of,n;
    scanf("%d %d",&of,&n);
    if(of<0||of>=n||n<0){
        printf("Error");
        return 1;
    }
    char *p;
    p=subStr(str1,of,n);
    if(p==NULL){

        return 1;
    }
    printf("%s",p);
    return 0;



}

    
