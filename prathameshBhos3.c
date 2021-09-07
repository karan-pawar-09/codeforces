#include<stdio.h>
double F1(double x) {
    double aa=x*x*x-14*x*x+35*x+50;
    return aa;
}
double F2(double x) {
    return (x*x-12*x-805);}
void root1(double a, double b) { 
    double val1=F1(a);
    double val2=F1(b);
    if (val1 * val2 >0) { 
        printf("no roots exist\n");
        return; 
    } 
    double c = a; 
    while ((b-a) >= 0.01) {
        c = (a+b)/2; 
        if (F1(c) == 0.0) 
            break; 
        else if (F1(c)*F1(a) <= 0) 
            b = c; 
        else
            a = c; 
    } 
    printf("%f",c);
} 
void root2 (double a,double b) {
   double val1=F2(a);
    double val2=F2(b);
    if (val1 * val2 >0) { 
        printf("no roots exist\n");
        return; 
    } 
    double c = a; 
    while ((b-a) >= 0.01) {
        c = (a+b)/2; 
        if (F2(c) == 0.0) 
            break; 
        else if (F2(c)*F2(a) <= 0) 
            b = c; 
        else
            a = c; 
    } 
    printf("%f",c);
}
int main() {
    int a,b;
    scanf("%d %d",&a,&b);
    printf("for F1: ");
    root1(a,b);
    printf("\nfor F2: ");
    root2(a,b);
    printf("\n");
}