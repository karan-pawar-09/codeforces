/*
    author:Karan
    created:11.09.2021 18:52:32
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve(int i,int n,vector<pair<int,int>> &arr) {
    
}
void solve() {
    int n,m;
    cin>>n>>m;
    int a,b;
    vector<pair<int,int>> arr(m)
    for(int i=0;i<m;i++) {
        cin>>arr[i].first>>arr[i].second;        
    }
    for(int i=0;i<n;i++) {
        solve(i,n,arr);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}