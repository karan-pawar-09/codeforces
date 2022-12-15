/*
    author:Karan
    created:15.12.2022 11:57:11
*/

#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int start, end;
    cin>>start>>end;
    for(int i=0;i<n;i++) {
        if(arr[i]>=start && arr[i]<=end) {
            cout<<arr[i]<<" ";
        }
    }
    cout<<endl;
}

int main() {
   
    solve();
    
}