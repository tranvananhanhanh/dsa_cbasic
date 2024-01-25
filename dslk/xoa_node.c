#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int value;
    struct Node *next;
}Node;
//xóa 1 nút có gtri v
Node *remove(Node *h,int v){
    if(h==NULL) return NULL;
//lưu trữ con trỏ tới nút cần loại bỏ trong biến delete. Tiếp theo, ta cập nhật con trỏ h để trỏ tới nút kế tiếp (h->next). Sau đó, ta giải phóng bộ nhớ đã được cấp phát cho nút cần loại bỏ bằng cách sử dụng hàm free. Cuối cùng, ta trả về con trỏ h đã được cập nhật.
    if(h->value==v){
        Node *delete=h;
        h=h->next;
        free(delete);
        return h;
    }
    h->next=remove(h->next,v);
    return h;
}
// xóa tất cả các nút gtri v  
Node *removeall(Node *h,int v){
    if(h==NULL){
        return NULL;
    }
    if(h->value==v){
        Node *p=h;
        h=h->next;
        free(p);
        h=removeall(h,v);
    }
    h->next=removeall(h->next,v);
    return h;
}
//đảo ngược thứ tự node
Node *reverse(Node *h){
    Node *p=h;
    Node *pp=NULL;
    Node *np=NULL;
    while(p!=NULL){
        np=p->next;
        p->next=pp;
        pp=p;
        p=np;
    }
    return pp;
}