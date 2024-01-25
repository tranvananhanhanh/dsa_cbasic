#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Node{
    struct Node  *left;
    struct Node *right;
    char name[100];
    char email[100];
}Node;
Node *root;
Node *newnode(char name[],char email[]){
    Node *p=(Node*)malloc(sizeof(Node));
    strcpy(p->name,name);
    strcpy(p->email,email);
    p->left=NULL;
    p->right=NULL;
}
//chèn khóa nhở hơn vào trái , lớn hơn vào phải
Node *insert(Node *root,char name[],char email[]){
    if(root==NULL){
        root=newnode(name,email);
        return root;
    }
    int c=strcmp(root->name,name);
        if(c==0){
            return root;
        }
        else if(strcmp(root->name,name)==1){
            root->left=insert(root->left,name,email);
            //return left child
            return root;
        }
        else if(strcmp(root->name,name)==-1){
            root->right=insert(root->right,name,email);
            //return right child
            return root;
        }
    }

Node *find(Node *root,char name[]){
    if(root==NULL){
        return NULL;
    }
    else{
        if(strcpy(root->name,name)==0){
            return root;
        }
        else if(strcpy(root->name,name)>0){
            return(find(root->left,name));
            }
        return(find(root->right,name));
        }
    }
Node *findmin(Node *root){
    if(root==NULL){
        return;
    }
    Node *min=findmin(root->left);
    if(min!=NULL){
        return min;
    }
    return root;
}
Node* removeStudent(Node* r, char* name){
    if(r == NULL) return NULL;
    int c = strcmp(r->name,name);
    if(c > 0) r->left= removeStudent(r->left,name);
    else if(c < 0) r->right = removeStudent(r->right,name);
    else{
        if(r->left != NULL && r->right != NULL){
        Node* tmp = findMin(r->right);
         strcpy(r->name,tmp->name); 
         strcpy(r->email,tmp->email); 
         r->right = removeStudent(r->right,tmp->name);
        }else{
            Node* tmp = r;
            if(r->left == NULL) r = r->right; 
            else r = r->left;
            free(tmp);
            }
        }   
    return r;
    }


