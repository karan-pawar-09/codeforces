/*
author:Karan
created:28.05.2021 20:08:04
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        n=2*n;
        vector<ll> arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        sort(all(arr));
        
        for(int i=1;i<n-1;i++) {
            if(arr[i]+arr[i]==arr[i-1]+arr[i+1]) {
                swap(arr[i-1],arr[i]);
            }
        }
        if(arr[0]+arr[0]==arr[1]+arr[n-1]) {
            swap(arr[0],arr[n-1]);
        }
        if(arr[n-1]+arr[n-1]==arr[0]+arr[n-2]) {
            swap(arr[n-1],arr[n-2]);
        }
        for(int i=1;i<n-1;i++) {
            if(arr[i]+arr[i]==arr[i-1]+arr[i+1]) {
                swap(arr[i-1],arr[i]);
            }
        }
        for(int i=0;i<n;i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}