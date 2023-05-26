/*
    author:Karan
    created:11.02.2023 21:12:36
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

const ll inf = 1e18+10;
const ll mx = 18;
ll arr[mx][mx];
ll dp[mx][mx];
ll dp1[mx][mx];
ll temp;
ll answer;

void res(ll start, ll end, ll bitmask, ll val, ll prev) {
    ll k = __builtin_popcount(bitmask);
    if(k==(end-start)) {
        int sum = 0;
        val += arr[prev][end];
        temp = min(temp, val);
        return;
    }
    for(ll i=start;i<end;i++) {
        if(!(bitmask&(1<<i))) {
            bitmask ^= (1<<i);
            ll kp = val;
            if(prev != -1) {
                kp += arr[prev][i];
            }
            res(start, end, bitmask, kp, i);
            bitmask ^= (1<<i);
        }
    }
}

ll calc(vector<ll> &ar, ll end) {
    ll prev = 0;
    ll count = 0;
    for(auto x: ar) {
        count += dp[prev][x];
        count += arr[x][end];
        prev = x+1;
    }
    count += dp[prev][end];
    return count;
}

void rec(ll i, ll end, vector<ll> &splits, int n) {
    if(i == end) {
        answer = min(answer, calc(splits, end));
        return;
    }
    splits.push_back(i);
    rec(i+1, end, splits, n);
    splits.pop_back();
    rec(i+1, end, splits, n);
}

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    for(ll i=0;i<=n+1;i++) {
        for(ll j=0;j<=n+1;j++) {
            dp[i][j] = 0;
            dp1[i][j] = -1;
            cin>>arr[i][j];
        }
    }
    answer = inf;
    for(ll i=0;i<=n+1;i++) {
        for(ll j=i;j<=n+1;j++) {
            temp = inf;
            res(i, j, 0, arr[0][i], -1);
            dp[i][j] = 2*temp;
        }
    }
    vector<ll> splits;
    rec(0, n+1, splits, n+1);
    cout<<x+y*answer<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}