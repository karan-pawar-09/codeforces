
#include<bits/stdc++.h>
using namespace std;


void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


int partition(int arr[], int low, int high){
    
        int pivot = arr[high];
        int i = (low - 1);
    
        for(int j = low; j < high; j++){
        
            if(arr[j] < pivot){
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        return (i + 1);
    }

void quicksort(int arr[], int low, int high)
    {
        
        if (low < high)
        {
            int pi = partition(arr, low, high);
    
            quicksort(arr, low, pi-1);
            quicksort(arr, pi + 1, high);
        }
}

void printarray(int arr[], int s){
    
    for (int i = 0; i < s; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    
        int arr[] = {10, 80, 30, 90, 40, 50, 70};
        
        int n = sizeof(arr) / sizeof(arr[0]);
        
        quicksort(arr, 0, n - 1);
        
        printarray(arr, n);
    
        return 0;
}