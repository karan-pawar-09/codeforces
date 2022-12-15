/*
    author:Karan
    created:04.12.2022 15:44:27
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
    ll n, x;
    cin>>n>>x;
    vector<int> ans(n+1);
    for(int i=1;i<=n;i++) {
        ans[i] = i;
    }
    ans[1] = x;
    ans[n] = 1;
    if(n%x != 0) {
        cout<<-1<<endl;
        return;
    }
    for(int i=x;i<n;i+=x) {
        if(n%i == 0) {
            ans[x] = i;
            ans[i] = n;
            x = i;
        }
    }
    for(int i=1;i<=n;i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}