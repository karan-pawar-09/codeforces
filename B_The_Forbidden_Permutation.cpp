/*
    author:Karan
    created:01.02.2023 20:56:57
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

const ll inf = 1e18+7;

void solve() {
    ll n, m, d;
    cin>>n>>m>>d;
    vector<ll> p(n);
    vector<ll> M(n);
    for(ll i=0;i<n;i++) {
        cin>>p[i];
        p[i]--;
        M[p[i]] = i;
    }
    vector<ll> a(m);
    for(ll i=0;i<m;i++) {
        cin>>a[i];
        a[i]--;
    }
    vector<pair<ll, ll>> dp(m);
    vector<pair<ll, ll>> indx(n);
    dp[0].first = 0;
    dp[0].second = 0;
    indx[a[0]].first = M[a[0]];
    indx[a[0]].second = M[a[0]];
    ll res = 1e18+10;
    for(ll i=1;i<m;i++) {
        ll temp = max(0LL, M[a[i]]-M[a[i-1]]);

        
        if(max(0LL, M[a[i-1]]+d+1 - M[a[i]]) <= (M[a[i-1]] + n-1-M[a[i]])) {
            temp = min(temp, max(0LL, M[a[i-1]]+d+1 - M[a[i]]));
            // M[a[i]] = M[a[i-1]]+d+1;
        } else {
            // M[a[i]] = M[a[i-1]];
        }
        
        res = min(res, temp);
            
        
    }
    cout<<res<<endl;
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