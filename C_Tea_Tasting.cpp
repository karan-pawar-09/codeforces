/*
    author:Karan
    created:17.02.2023 14:16:46
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

const ll mx = 2e5+10;
ll pre[mx];

ll binarysearch(ll p, ll k, ll start, vector<ll> &a) {
    ll n = a.size();
    ll l = start;
    ll r = n;
    while(l+1 < r) {
        ll m = (l+r)/2;
        if(p+k > pre[m]) {
            l = m;
        } else {
            r = m;
        }
    }
    if(p+k > pre[l]) {
        return l;
    } else {
        return l-1;
    }
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> b(n), a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(ll i = 0; i < n; i++) {
        cin >> b[i];
    }
    for(ll i=0;i<n;i++) {
        if(i==0) {
            pre[i] = b[i];
        } else {
            pre[i] = pre[i-1] + b[i];
        }
    }
    vector<ll> freq(n+1, 0);
    vector<ll> add(n+1, 0);
    for(ll i=0;i<n;i++) {
        ll k = 0;
        if(i-1 >= 0) {
            k += pre[i-1];
        }
        ll index = binarysearch(a[i], k, i, a);
        freq[i] += 1;
        freq[index +1] -= 1;
        add[index + 1] += a[i] - pre[index] + k;
    }
    for(ll i=0;i<n;i++) {
        cout<<freq[i]*b[i]+add[i]<<" ";
        freq[i+1] += freq[i]; 
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