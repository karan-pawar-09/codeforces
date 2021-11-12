/*
    author:Karan
    created:07.11.2021 22:13:59
*/
#if true
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
#define mset(a,x) memset(a,x,sizeof(a))
#endif

void solve() {
    int n;
    cin>>n;
    vector<int> t(n);
    vector<vector<int>> arr(n);
    queue<int> q;
    for(int i=0;i<n;i++) {
        cin>>t[i];
        int k;
        cin>>k;
        for(int j=0;j<k;j++) {
            int b;
            cin>>b;
            b--;
            arr[i].push_back(b);
        }
    }
    q.push(n-1);
    ll ans=0;
    vector<bool> visited(n,false);
    visited[n-1]=true;
    while(q.size()) {        
        int p=q.front();

        q.pop();                
        ans+=t[p];        
        for(auto x:arr[p]) {
            if(!visited[x]) {
                q.push(x);
                visited[x]=true;
            }
        }
    }
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