/*
    author:Karan
    created:03.08.2022 22:05:06
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

const ll mod=(ll)1e9+7;
const ll mx = (ll)1e8+6;

ll power(long long x, unsigned ll y, ll mod) {
    ll res = 1; 
    x = x % mod;   
    if (x == 0) return 0;  
    while (y > 0) {        
        if (y & 1)
            res = (res*x) % mod; 
        y = y>>1;
        x = (x*x) % mod;
    }
    return res;
}

ll add(ll a, ll b) {
    return (a+b)%mod;
}
void solve() {
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    vector<vector<ll>> dp(n, vector<ll> (11, mx));
    dp[0][0]=1;
    dp[0][1]=2;
    if(arr[0]-1>=0) {
        dp[0][2]=2;
    } else {
        dp[0][2]=mx;
    }
    for(ll i=1;i<n;i++) {
        for(int k=-5;k<=5;k++) {
            
        }
        {
            if(__gcd(arr[i], arr[i-1]) == 1) {
                dp[i][0] = min(dp[i][0],dp[i-1][0] + 1);
            } else {
                dp[i][0] = min(dp[i][0], mx);
            }
            if(__gcd(arr[i], arr[i-1]+1) == 1) {
                dp[i][0] = min(dp[i][0], dp[i-1][1] + 1);
            } else {
                dp[i][0] = min(dp[i][0], mx);
            }
            if(arr[i-1]-1 >=0 ) {
                if(__gcd(arr[i], arr[i-1]-1) == 1) {
                    dp[i][0] = min(dp[i][0], dp[i-1][2]+1);
                } else {
                    dp[i][0] = min(dp[i][0], mx);
                }
            } else {
                dp[i][0] = min(dp[i][0], mx);
            }
        }
        {
            if(__gcd(arr[i]+1, arr[i-1]) == 1) {
                dp[i][1] = min(dp[i][1], dp[i-1][0] + 2);
            } else {
                dp[i][1] = min(mx, dp[i][1]);
            }
            if(__gcd(arr[i]+1, arr[i-1]+1) == 1) {
                dp[i][1] = min(dp[i][1], dp[i-1][1] + 2);
            } else {
                dp[i][1] = min(dp[i][1], mx);
            }
            if(arr[i-1]-1 >=0 ) {
                if(__gcd(arr[i]+1, arr[i-1]-1) == 1) {
                    dp[i][1] = min(dp[i][1], dp[i-1][2]+2);
                } else {
                    dp[i][1] = min(dp[i][1], mx);
                }
            } else {
                dp[i][1] = min(dp[i][1], mx);
            }
        }
        {
            if(arr[i]-1 < 0) {
                dp[i][2] = mx;
            } else {
                if(__gcd(arr[i]-1, arr[i-1]) == 1) {
                    dp[i][2] = min(dp[i][2], dp[i-1][0] + 2);
                } else {
                    dp[i][2] = min(mx, dp[i][2]);
                }
                if(__gcd(arr[i]-1, arr[i-1]+1) == 1) {
                    dp[i][2] = min(dp[i][2], dp[i-1][1] + 2);
                } else {
                    dp[i][2] = min(dp[i][2], mx);
                }
                if(arr[i-1]-1 >=0 ) {
                    if(__gcd(arr[i]-1, arr[i-1]-1) == 1) {
                        dp[i][2] = min(dp[i][2], dp[i-1][2]+2);
                    } else {
                        dp[i][2] = min(dp[i][2], mx);
                    }
                } else {
                    dp[i][2] = min(dp[i][2], mx);
                }
            }
        }
    }

    cout<<min({dp[n-1][0], dp[n-1][1], dp[n-1][2]})<<endl;
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