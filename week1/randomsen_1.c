#include<stdio.h>
#include<stdlib.h>>
#include<ctype.h>
#include<time.h>

//khai báo các phần tử trong mảng với từng địa chỉ cụ thể để lưu giá trị biến áp dụng cho cả bài code--> dùng con trỏ
char* ar[]={"the","a","one","some","any"};
char* n[]={"boy","girl","dog","car","town"};
char* v[]={"drive","go","run","sing","sing"};
char* pr[]={"to","from","over","under","on"};
//hàm chọn số ngẫu nhên từ 0 đến max-1
int getrandomindex(int max){
    return rand() %max;
}
//hàm tạo câu
void generate(){
    char* ar_1=ar[getrandomindex(5)];
    char* n_1=n[getrandomindex(5)];
    char* v_1=v[getrandomindex(5)];
    char* pr_1=pr[getrandomindex(5)];
    char* n_2=n[getrandomindex(5)];
    printf("%c%s %s %s %s %s.\n ",toupper(*ar_1),ar_1+1,n_1,v_1,pr_1,n_2);

}
int main(){
    // khởi tạo seed cho số ngẫu nhiên
    srand(time(NULL));
    int num=10;
    for (int i=0;i<num;i++){
        generate();
    }
    return 0;
}