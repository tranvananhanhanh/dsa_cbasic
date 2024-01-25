#include<stdio.h>
//các bước lần lượt , chuyển n-1 đĩa đầu sang trung gian, chuyển đĩa cuiối về đích, chuyển n-1 đĩa đầu về đích 
int count=0;
void move(int n,char a,char b,char c){
    if(n==1){
        count++;
        printf("step %d: move disk from %c to %c\n",count,a,c);
    }
    else{
        move(n-1,a,c,b);
        move(1,a,b,c);
        move(n-1,b,a,c);
    }

}
int main(){
    move(4,'A','B','C');
}