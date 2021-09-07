#include<bits/stdc++.h>
using namespace std;

int maxSubarray(int arr[],int size) {
    int max_current=arr[0];
    int max_overall=arr[0];
    for(int i=1;i<size;i++) {
        max_current = max(arr[i],arr[i]+max_current);
        max_overall = max(max_overall,max_current);
    }
    return max_overall;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int max = maxSubarray(arr,n);
    cout<<max;
}