#include<stdio.h>

int main() {
    int a,b;
    scanf("%d %d",&a,&b);
    int arr[a];
    int ar[b];
    for(int i=0;i<a;i++) {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<b;i++) {
        scanf("%d",&ar[i]);
    }
    int i=0;
    int j=0;
    int z=0;
    int ans[a+b];
    if(j<b) {
        ans[0]=ar[0];
        j++;
        z++;
    }
    while(j<b&&i<a) {
        ans[z]=arr[i];
        i++;
        z++;
        if(j<b&&i<a) {
            ans[z]=arr[i];
            i++;
            z++;
        }
        if(j<b&&i<a) {
            ans[z]=ar[j];
            j++;
            z++;
        }
        if(j<b&&i<a) {
            ans[z]=ar[j];
            j++;
            z++;
        }
    }
    if(j<b) {
        for(j;j<b;j++) {
            ans[z]=ar[j];
            z++;
        }
    }
    if(i<a) { 
        for(i;i<a;i++) {
            ans[z]=arr[i];
            z++;
        }
    }
    for(int t=0;t<a+b;t++) {
        printf("%d ",ans[t]);
    }
}