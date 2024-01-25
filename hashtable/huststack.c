#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 10000
int hash(char s[], int m) {
    int i = 0;
    int k = strlen(s);
    int total = 0;

    while (i < k) {
        total = (total * 256 + s[i]) % m;
        i++;
    }

    return total;
}
int main(){
    char bff[MAX];
    int n;
    int m;
    fgets(bff,MAX,stdin);
    sscanf(bff,"%d %d",&n,&m);
    int i=0;
    while (i<n)
    {   
        char buff[MAX];
        char s[MAX];
        fgets(buff,MAX,stdin);
        sscanf(buff,"%s",s);
        printf("%d\n",hash(s,m));
        i++;
        /* code */
    }
    
}
