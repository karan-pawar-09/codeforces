#include<stdio.h>

int main() {
    int a[5];
    int sum=0;
    for(int i=0;i<5;i++) {
        scanf("%d",&a[i]);
        sum+=a[i];
    }    
    int per=(sum*100/500);
    if(per>=60) {
        printf("First Div");
    }
    else if(per>=50) {
        printf("Second Div");
    }
    else if(per>=40) {
        printf("Third Div");
    }
    else {
        printf("Fail");
    }
}   