/*
author:Karan
created:05.09.2021 18:58:19
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    ll n;
    cin>>n;
    vector<ll> c(n);
    for(ll i=0;i<n;i++) {
        cin>>c[i];
    }
    ll res = 0;
    
    for (int i = 0; i < n; i += 2) {
        ll mn = c[i];
        ll cur = c[i];
        for (int j = i + 1; j < n; j++) {
            if (j % 2 == 0) {
                cur += c[j];
            } else {
                ll l = max(0LL, cur - c[j]);
                ll r = min({mn, cur - 1LL, c[i] - 1LL});
                if (l <= r) {
                    res += r - l + 1;
                }
                cur -= c[j];
                mn = min(mn, cur);
            }
        }
    }
    cout<<res<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}