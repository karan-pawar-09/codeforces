/*
    author:Karan
    created:22.11.2021 20:59:40
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
    string s,t;
    cin>>s>>t;
    bool prev=false;
    int ans=0;
    for(int i=n-1;i>=0;i--) {
        if(s[i]<t[i]) {
            ans++;
            prev=true;
        }
        else if(t[i]<s[i]) {
            prev=false;
        }
        else {
            if(prev) {
                ans++;
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
    cin>>t;
    while(t--) {
        solve();
    }
}