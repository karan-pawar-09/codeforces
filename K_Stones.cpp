/*
author:Karan
created:23.05.2021 14:54:25
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    vector<bool> ans(k+1,false);
    for(int i=0;i<=k;i++) {
        for(int x:arr) {
            if(i>=x&&!ans[i-x]) {
                ans[i]=true;
            }
        }
    }
    if(ans[k]) {
        cout<<"First"<<endl;
    }
    else {
        cout<<"Second"<<endl;
    }
}