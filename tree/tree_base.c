#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Node{
    int id;
    struct Node *leftmostchild;
    struct Node *rightsibling;
}Node;
Node *newnode(int i){
    Node *t=(Node*)malloc(sizeof(Node));
    t->id=i;
    t->leftmostchild=NULL;
    t->rightsibling=NULL;
    return t;
}
void makeroot(Node **root,int i){
    *root=newnode(i);
}
//sd de quy
Node *find(Node *root,int v){
    if(root->id==v){
        //base case
        return root;
    }
    Node *p=root->leftmostchild;
    while(p!=NULL){
        Node *p1=find(p,v);
        if(p1==NULL){
            p=p->rightsibling;
        }
        else{
            return p1;
        }
    }
    return NULL;
}
//add last child
void insert(Node *root,int u,int v){
    Node *t=find(root,v);
    Node *t1=find(root,u);
    Node *t2=newnode(u);
    if(t==NULL||t1!=NULL){
        return;
    }
    else{
        Node *tl=t->leftmostchild;
        if(tl==NULL){
            t->leftmostchild=t2;
        }
        else{
            while(tl->rightsibling!=NULL){
                tl=tl->rightsibling;
            }
            tl->rightsibling=t2;
        }
    }
}
void inoder(Node *root){
    //điều kiện kết thúc đệ quy
    if(root==NULL){
        return;
    }
    //tìm đến vị trí con trái nhất
    Node *p=root->leftmostchild;
    inoder(p);
    //in ra địa chỉ
    printf("%d ",root->id);
    if(p==NULL){
        return;
    }
    //chuyển sang làm tương tự với e bên phải
    p=p->rightsibling;
    while(p!=NULL){
        inoder(p);
        p=p->rightsibling;
    }
}
void preoder(Node *root){
    if(root==NULL){
        return;
    }
    //visit root first
    printf("%d ",root->id);
    //go to left
    Node *p=root->leftmostchild;
    while(p!=NULL){
        preoder(p);
        //go to right
        p=p->rightsibling;
    }
    
}
void postoder(Node *root){
    if(root==NULL){
        return;
    }
    Node *p=root->leftmostchild;
    while(p!=NULL){
        postoder(p);
        p=p->rightsibling;
    }
    printf("%d ",root->id);
    
}
void freetree(Node *root) {
    if (root != NULL) {
        freetree(root->leftmostchild);
        freetree(root->rightsibling);
        free(root);
    }
}
int height(Node *root) {
    int max = 0;
    if (root == NULL) {
        return 0;
    }
    
    // Loop should use p = p->rightsibling instead of p->rightsibling
    for (Node *p = root->leftmostchild; p != NULL; p = p->rightsibling) {
        int h = height(p);
        if (h > max) {
            max = h;
        }
    }
    // Each recursive call represents a path length, so return max + 1
    return max + 1;
}
int leaf(Node *r){
    int k=0;
    if(r==NULL){
        return 0;
    }
    if(r->leftmostchild==NULL){
        return 1;
    }
    Node *p=r->leftmostchild;
    while(p!=NULL){
        k=k+leaf(p);
        p=p->rightsibling;
    }
    return k;
}


int main(){
    Node *root;
    makeroot(&root,1);
    insert(root,2,1);
    insert(root,3,1);
    insert(root,4,3);
    insert(root,5,3);
    preoder(root);
    printf("\n%d",height(root));
    printf("\n%d",leaf(root));
    return 0;
    
}














