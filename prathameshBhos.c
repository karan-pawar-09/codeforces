#include<stdio.h>

int main() {
    float a,b,c,d,t1;
    scanf("%f %f %f %f %f",&a,&b,&c,&d,&t1);
    float ans=(3*a*t1*t1)+(2*b*t1)+c;
    printf("%f\n",ans);
}