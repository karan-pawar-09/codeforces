/*
author:Karan
created:10.07.2021 18:27:09
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
    vector<stirng> arr(n);
    map<string,int> M;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        string k;
        for(int j=0;j<3;j++) {
            k.push_back(arr[i][j]);
        }
        M[k]++;
    }
    for(int i=0;i<n;i++) {
        
    }
}

