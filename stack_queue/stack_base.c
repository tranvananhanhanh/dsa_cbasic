#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//stack arrayy

typedef struct Node {
    int ms;
    char name[MAX];
} Node;

//truyền vào địa chỉ để thay đổi địa chỉ mảng,truyền tham chiếu để thay đoiỉ giá trị ngoài hàm của N
void stackinit(Node **a, int *N) {
    *a = (Node*)malloc(MAX * sizeof(Node));
    *N = 0;
}

int isempty(int N) {
    return N == 0;
}
//truyền vào để thay đổi nội dung mẩng chứ k thay đổi địa chỉ mảng 
void stackpush(Node *a, int *N, int ms, char name[]) {
    a[*N].ms = ms;
    strcpy(a[*N].name, name);
    (*N)++;
}

Node stackpop(Node *a, int *N) {
    (*N)--;
    return a[*N];
}

int main() {
    Node *arr;
    int N;
    stackinit(&arr, &N);

    int ms;
    char name[MAX];

    while (1) {
        scanf("%d", &ms);
        if (ms == 0) {
            break;
        }
        scanf("%s",name);
        stackpush(arr, &N, ms, name);
    }

    Node poppedNode = stackpop(arr, &N);

    printf("%d %s\n", poppedNode.ms, poppedNode.name);
    printf("%d",N);
    free(arr);

    return 0;
}





//stack linked list, truyền địa chỉ vào những vị trí của hàm làm thay đổi địa chỉ
typedef struct Node{
    char c;
    struct Node *next;
}Node;
Node *new(char ce){
    Node *t=(Node*)malloc(sizeof(Node));
    t->c=ce;
    t->next=NULL;
    return t;
}
 void stackinit(Node **top){
     *top=NULL;
 }
 int stackempy(Node *top){
     return top==NULL;
 }
 //thêm vào đầu dslk đơn,lấy đầu dslk 
void stackpush(Node **top,char ce){
    if(*top==NULL){
        *top=new(ce);
    }
    else{
        Node *t=new(ce);
        t->next=*top;
        *top=t;
    }
}
char stackpop(Node **top){
    if(stackempy(*top)){
        return -1;
    }
    Node *temp=*top;
    char ce=temp->c;
    *top=temp->next;
    free(temp);
    return ce;
}
int main(){
    Node *top;
    stackinit(&top);
    char ic;
    while(1){
        //lệnh này đọc cả dấu cách/tab/n vào biến
        scanf("%c",&ic);
        if(ic=='*'){
            break;
        }
        stackpush(&top,ic);
    }
    char i=stackpop(&top);
    printf("%c",i);
}
 
 