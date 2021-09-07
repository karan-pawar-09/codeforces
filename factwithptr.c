#include<stdio.h>

int fact(int *x) {
    printf("calling factorial %d \n",*x);
    if(*x==1||*x==0) {
        return 1;
    }
    int k=(*x)-1;
    return (*x) * fact(&k);
}

int main() {
    int n;
    scanf("%d",&n);
    int ans=fact(&n);
    printf("fact is %d",ans);
}