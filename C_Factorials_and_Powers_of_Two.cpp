/*
    author:Karan
    created:04.03.2022 21:33:46
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

const ll mx = (ll)1e12;
set<ll> arr;
vector<ll> p;
ll ans,n;
void rec(ll i,ll res,ll used) {
    if(i>=14) {    
        if(n>=res)    
            ans=min(ans,(ll)(used+(__builtin_popcountll(n-res))));
        return;
    }
    rec(i+1,res+p[i],used+1);
    rec(i+1,res,used);
}
void solve() {
    cin>>n;
    ans=100;
    rec(0,0,0);
    cout<<ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    cin>>t;
    ll prev=1;
    arr.insert(1);
    for(ll i=1;i<64;i++) {
        ll k=prev*i;
        if(k<=mx) {
            arr.insert(k);
        } else {
            break;
        }
        prev=k;
    } for(auto x:arr) p.push_back(x);
    while(t--) {
        solve();
    }
}