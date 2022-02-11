/*
    author:Karan
    created:30.01.2022 17:32:52
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
    string s;
    cin>>s;
    vector<int> next(n+10,-1);
    vector<int> prev(n+10,-1);
    for(int i=1;i<=n;i++) {
        if(s[i-1]=='L') {
            int p=prev[i-1];
            next[i]=i-1;
            prev[i]=prev[i-1];
            prev[i-1]=i;
            if(p!=-1)
                next[p]=i;
        } else {
            int n=next[i-1];
            prev[i]=i-1;
            next[i]=next[i-1];
            next[i-1]=i;
            if(n!=-1)
                prev[n]=i;
        }
    }
    int k=0;
    while(prev[k]!=-1) {
        k=prev[k];
    }
    vector<int> ans;
    while(k!=-1) {
        ans.push_back(k);
        k=next[k];
        if(k==-1) {
            break;
        }
    }
    for(auto x:ans)cout<<x<<" ";
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