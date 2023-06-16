/*
    author:Karan
    created:12.06.2023 21:12:27
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

const ll inf = (long long) 1e18+7;

void solve() {
    string s;
    cin >> s;
    ll n = s.size();
    map<char, ll> arr;
    arr['A'] = 1;
    arr['B'] = 10;
    arr['C'] = 100;
    arr['D'] = 1000;
    arr['E'] = 10000;
    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>> (5, vector<ll> (2, -inf)));
    dp[n][0][0] = 0;
    for(ll i = n - 1; i >= 0; i--) {
        for(char mx = 'A'; mx <= 'E'; mx++) {
            for(ll changed = 0; changed <= 1; changed++) {
                for(char nw = 'A'; nw <= 'E'; nw++) {
                    ll new_changed = changed + (nw != s[i]);
                    ll new_mx = max(mx, nw);
                    ll val = dp[i+1][mx-'A'][changed] + (nw < mx ? -1:1) * arr[nw];
                    if(new_changed <= 1) {
                        dp[i][new_mx-'A'][new_changed] = max(dp[i][new_mx-'A'][new_changed], val);
                    }
                }
            }
        }
    }
    ll ans = -inf;
    for(auto x: dp[0]) {
        for(auto y: x) {
            ans = max(ans, y);
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



