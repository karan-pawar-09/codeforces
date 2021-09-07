#include<stdio.h>

void swap(int *a,int *b);
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);

int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    heapSort(arr,n);
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void swap(int *a,int *b) {
    int c=*a;
    *a=*b;
    *b=c;
}

void heapify(int arr[], int n, int i) {
    int largest=i;
    if((2*i+1)<n && arr[(2*i+1)]>arr[largest]) {
        largest = (2*i+1);
    }
    if((2*i+2)<n && arr[(2*i+2)]>arr[largest]) {
        largest = (2*i+2);
    }
    if(largest !=i) {
        swap(&arr[i],&arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[], int n) {
    for(int i=(n/2)-1;i>=0;i--) {
        heapify(arr,n,i);
    }
    for(int i=n-1;i>0;i--) {
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}