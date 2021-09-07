#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int start=0,end=n-1;
    int sereja=0,dima=0;
    int i=0;
    while(start<=end) {
        if(i%2==0){
            if(arr[start]>arr[end]){
                sereja+=arr[start];
                start++;
            }
            else{
                sereja+=arr[end];
                end--;
            }
        }
        else{
            if(arr[start]>arr[end]){
                dima+=arr[start];
                start++;
            }
            else{
                dima+=arr[end];
                end--;
            }
        }
        i++;
    }
     cout<<sereja<<" "<<dima;
}