/*
    author:Karan
    created:12.02.2023 15:02:19
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
    ll a, b;
    cin>>a>>b;
    vector<ll> ans;
    ll k = b+2;
    while(k<=a) {
        ans.push_back(k);
        k++;
    }
    k--;
    k--;
    while(k>=b) {
        ans.push_back(k);
        k--;
    }
    k++;
    k++;
    while(k<(b+2)) {
        ans.push_back(k);
        k++;
    }

    cout<<ans.size()<<endl;
    for(auto x: ans) {
        cout<<x<<" ";
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