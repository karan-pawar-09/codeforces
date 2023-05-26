/*
    author:Karan
    created:12.02.2023 15:35:50
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

ll calc(ll n) {
    return (n*(n+1))/2;
}

void solve() {
    ll n;
    cin>>n;
    vector<ll> p(n), q(n);
    map<ll, ll> M1, M2;

    for(ll i=0;i<n;i++) {
        cin>>p[i];
        M1[p[i]] = i;
    }

    for(ll j=0;j<n;j++) {
        cin>>q[j];
        M2[q[j]] = j;
    }

    ll l = n;
    ll r = -1;
    ll ans = 0;
    for(ll i=1;i<=n;i++) {
        if(i==1) {
            l = min(l,  min(M1[i], M2[i]));
            r = max(r, max(M1[i], M2[i]));
            ans += calc(l) + calc(r-l-1) + calc(n-1-r);
        } else {
            
            int x = min(M1[i],M2[i]);
            int y = max(M1[i],M2[i]);
            if(x < l && y > r) {
                ans += (l-x) * (y-r);
            } else if(y < l) {
                ans += (l-y) * (n-r);
            } else if(x > r) {
                ans += (x-r) * (l+1);
            }
            
        }
        l = min(l,  min(M1[i], M2[i]));
        r = max(r, max(M1[i], M2[i]));
    }

    cout<<ans+1<<endl;
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