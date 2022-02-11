/*
    author:Karan
    created:11.02.2022 22:41:00
*/
#if true
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
#define mset(a,x) memset(a,x,sizeof(a))
#endif

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int> (2));
    for(int i=0;i<n;i++) {
        cin>>arr[i][0]>>arr[i][1];
    }
    set<int> col,row;
    for(int i=0;i<n;i++) {
        col.insert(arr[i][1]);
        row.insert(arr[i][0]);
    }
    int ans=col.size()*(8);
    ans+=row.size()*(8);
    ans-=row.size()*col.size();
    cout<<ans<<endl;
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