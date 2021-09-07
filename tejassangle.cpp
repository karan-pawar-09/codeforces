/*
author:Karan
created:18.08.2021 11:13:50
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    if(n==0) {
        cout<<0<<endl;
    }
    else if(n==1) {
        cout<<arr[0]<<endl;
    }
    else {
        sort(arr.begin(),arr.end());
        if(arr[0]*arr[1]>=arr[n-1]*arr[n-2]) {
            cout<<arr[0]+arr[1]<<endl;
        }
        else {
            cout<<arr[n-2]+arr[n-1]<<endl;
        }
    }
}