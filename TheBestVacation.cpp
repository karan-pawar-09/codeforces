#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,x;
    cin>>n>>x;
    vector<long> arr;
    for(int i=0;i<n;i++) {
        long a;
        cin>>a;
        for(int j=1;j<=a;j++) {
            arr.push_back(j);
        }
    }
    for(int i=0;i<arr.size();i++) {
        arr.push_back(arr[i]);
    }
    long long max=0;
    for(int i=0;i<x;i++) {
        max+=arr[i];
    }
    for(int i=x;i<arr.size();i++) {
        int a=max+arr[i]
    }
}