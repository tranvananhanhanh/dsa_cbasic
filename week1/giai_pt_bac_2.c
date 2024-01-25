#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[]) {
    if (argc !=4){
        return 1;
    }
    int a,b,c;
    a=atoi(argv[1]);
    b=atoi(argv[2]);
    c=atoi(argv[3]);
    float d;
    d=b*b-4*a*c;
    float x1,x2;
    if (d > 0) {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
        printf("x1= %f\n", x1);
        printf("x2= %f\n", x2);
    } else if (d == 0) {
        x1 = -b / (2 * a);
        printf("x1=x2= %f\n", x1);
    } else {
        printf("pt vô nghiệm ");
    }

    return 0;
}