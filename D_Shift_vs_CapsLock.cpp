/*
    author:Karan
    created:27.05.2023 18:03:48
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
    ll x, y, z;
    cin>>x>>y>>z;
    string s;
    cin >> s;
    ll n = s.size();
    vector<vector<ll>> dp(n+1, vector<ll> (2, inf));
    dp[0][0]=0;
    dp[0][1]=z;
    char prev = 'a';
    for(ll i=1;i<=n;i++) {
        
        if(s[i-1]=='A') {
            {
                ll one = dp[i-1][1]+x+z;
                ll two = dp[i-1][0]+y;
                ll three = dp[i-1][0]+z+x+z;
                dp[i][0] = min({one, two, three});
            } 
            {
                ll one = dp[i-1][1]+x;
                ll two = dp[i-1][0]+y+z;
                ll three = dp[i-1][0]+z+x;
                dp[i][1] = min({one, two, three});
            }
        } else {
            {
                ll one = dp[i-1][0]+x;
                ll two = dp[i-1][1]+y+z;
                ll three = dp[i-1][1]+z+x;
                dp[i][0] = min({one, two, three});
            }
            {
                ll one = dp[i-1][0]+x+z;
                ll two = dp[i-1][1]+y;
                ll three = dp[i-1][1]+x+z+z;
                dp[i][1] = min({one, two, three});
            }
        }
    }
    
    cout<<min(dp[n][0], dp[n][1])<<endl;

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