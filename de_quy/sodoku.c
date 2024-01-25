#include<stdio.h>
int x[9][9];
int markR[9][10],markC[9][10];
int markS[3][3][10];
void ps(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            printf("%d",x[i][j]);
        }
        printf("\n");
    }
}
int check(int v,int r,int c){
    if(markR[r][v]) return 0;
    if(markC[c][v]) return 0;
    if(markS[r/3][c/3][v]) return 0;
    return 1;
}

void TRY(int r, int c){
    for(int v=1;v<=9;v++){
        if(check(v,r,c)){
            x[r][c]=v;
            markR[r][v]=1;
            markC[c][v]=1;
            markS[r/3][c/3][v]=1;
            if(r==8&&c==8){
                ps();
            }
            else{
                if(c==8){
                    TRY(r+1,0);
                }
                else{
                    TRY(r,c+1);
                }
            }
            markR[r][v]=0;
            markC[c][v]=0;
            markS[r/3][c/3][v]=0;

        }
    }
}
int main(){
    for(int v=1;v<=9;v++){
        for(int r=0;r<=8;r++){
            markR[r][v]=0;
        }
        for(int c=0;c<=8;c++){
            markC[c][v]=0;
        }
        for(int I=0;I<=8;I++){
            for(int J=0;J<=8;J++){
            markS[I][J][v]=0;}
        }
    }
    TRY(0,0);
}