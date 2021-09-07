#include<stdio.h>
#include<stdlib.h>

void merge(int arr[],int l,int m,int r) {
    int L[m-l+1],R[r-m];
    for(int i=0;i<(m-l+1);i++) {
        L[i]=arr[l+i];
    }
    for(int i=0;i<(r-m);i++) {
        R[i]=arr[m+1+i];
    }
    int i=0;
    int j=0;
    int k=l;
    while(i<(m-l+1)&&j<(r-m)) {
        if(L[i]<=R[j]) {
            arr[k]=L[i];
            i++;
        }
        else {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<(m-l+1)) {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<(r-m)) {
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int l,int r) {
    if(l<r) {
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
}