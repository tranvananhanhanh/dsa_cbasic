#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 100
char  *my_cat(char *s1,char *s2){
    int len1,len2;
    char *result;
    len1=strlen(s1);
    len2=strlen(s2);
    result=(char*)malloc((len1+len2+1)*sizeof(char));
    if(result==NULL){
        printf("Fail");
        return NULL;
    }
    //copy s1 vào result
    strcpy(result,s1);
    //copy s2 vào vị trí mới của result
    strcpy(result+len1,s2);
    return result;

}
int main(){
    char str1[MAX_LEN+1],str2[MAX_LEN+1];
    char *cat_str;
    scanf("%s",str1);
    scanf("%s",str2);
    cat_str=my_cat(str1,str2);
    if(cat_str==NULL){
        printf("FAIL");
        return 1;
    }
    printf("%s+%s=%s",str1,str2,cat_str);
    free(cat_str);
    return 0;



}
