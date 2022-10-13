/*
    author:Karan
    created:30.08.2022 21:48:08
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

ll mat[1010][1010];
ll pref[1010][1010];

void solve() {
    ll n, q;
    cin>>n>>q;

    for(ll i=0;i<1010;i++) {
        for(ll j=0;j<1010;j++) {
            mat[i][j] = 0;
            pref[i][j] = 0;
        }
    }

    for(ll i=0;i<n;i++) {
        ll a, b;
        cin>>a>>b;
        mat[a][b] += (a*b);
    }
    
    for(ll i=1;i<=1000;i++) {
        for(ll j=1;j<=1000;j++) {
            pref[i][j] = pref[i-1][j] + pref[i][j-1] + mat[i][j] - pref[i-1][j-1];
        }
    }

    while(q--) {
        ll a, b, c, d;
        cin>>a>>b>>c>>d;
        c--;
        d--;
        cout<<max(0, pref[c][d] - pref[c][b] - pref[a][d] + pref[a][b])<<endl;
    }
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
