/*
    author:Karan
    created:15.06.2023 13:00:31
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

void sub(vector<ll> &a, vector<ll> &b) {
    ll n = a.size();
    for(ll i = 0; i < n; i++) {
        a[i] -= b[i];
    }
}

void add(vector<ll> &a, vector<ll> &b) {
    ll n = a.size();
    for(ll i = 0; i < n; i++) {
        a[i] += b[i];
    }
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> row(n, vector<ll> (31, 0));
    vector<vector<ll>> col(m, vector<ll> (31, 0));
    vector<vector<ll>> arr(n, vector<ll> (m));
    vector<ll> dp(31, 0);
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            cin >> arr[i][j];
            for(ll k = 0; k < 31; k++) {
                if((arr[i][j]&(1 << k))) {
                    dp[k]++;
                    row[i][k]++;
                    col[j][k]++;
                }
            }
        }
    }
    ll maxi = 0;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            vector<ll> one = row[i];
            vector<ll> two = col[j];
            vector<ll> three(31, 0);
            for(ll k = 0; k < 31; k++) {
                if(arr[i][j] & (1 << k)) {
                    three[k]++;
                }
            }
            sub(dp, one);
            sub(dp, two);
            add(dp, three);
            ll total = (n * m) - (n + m - 1);
            ll res = 0;
            for(ll k = 0; k < 31; k++) {
                if(arr[i][j] & (1 << k)) {
                    res += (1 << k) * (total - dp[k]);
                } else {
                    res += (1 << k) * (dp[k]);
                }
            }
            add(dp, one);
            add(dp, two);
            sub(dp, three);

            maxi = max(maxi, res);
        }
    }
    cout<<maxi<<endl;
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