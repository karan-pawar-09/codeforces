/*
    author:Karan
    created:30.05.2023 19:50:21
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


//a[i]*a[i] = b[i] + b[j]
//(a[i]^2) - b[i] = b[j]

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    map<ll,vector<ll>>mpp;
    for(ll i =0; i < n; i++) {
        cin >> a[i];
    }
    for(ll j = 0; j < n; j++) {
        cin >> b[j];
    }
    for(ll i = 0; i < n; i++) {
        mpp[a[i]].push_back(b[i]);
    }
    ll ans = 0;
 
    for(ll aj = 1; aj * aj <= 2*n; aj++) {
        vector<ll> bj(n+1, 0);
        for(ll i = 0; i < n; i++) {
            if(aj == a[i]) {
                bj[b[i]]++;
            }
        }
        for(ll i = 0; i < n; i++) {
            if(aj < a[i] && (a[i] * aj - b[i] >= 0) && (a[i] * aj - b[i] <= n)) {
                ans += bj[a[i]*aj - b[i]];
            }
        }
    }

    for(auto x: mpp) {
        ll ai = x.first;
        vector<ll> temp = x.second;
        map<ll, ll> B;
        for(auto y: temp) {
            ans += B[(ai*ai) - y];
            B[y]++;
        }
    }
    cout<<ans<<endl;
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