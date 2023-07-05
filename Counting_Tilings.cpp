/*
    author:Karan
    created:26.06.2023 12:16:43
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

const ll mod = 1e9+7;
const ll mx = 1e3+30;
ll dp[mx][mx];

ll add(ll a, ll b) {
    return ((a % mod) + (b % mod)) % mod;
}

bool valid(ll no, ll n) {
    ll zero = 0;
    for(ll i = 0; i < n; i++) {
        if(no & (1 << i)) {
            if(zero%2) return false;
            zero = 0;
        } else {
            zero++;
        }
    }
    if(zero%2) return false;
    return true;
}

void makeNext(ll cur, ll next, ll index, ll n, vector<ll> &arr) {
    if(index == n) {
        if(valid(cur|next, n)) {
            arr.push_back(next);
        }
        return;
    }
    if(cur & (1 << index)) {
        makeNext(cur, next, index + 1, n, arr);
    } else {
        makeNext(cur, next, index + 1, n, arr);
        next |= (1 << index);
        makeNext(cur, next, index + 1, n, arr);
    }
}

ll rec(ll mask, ll i, ll m, ll n) {
    if(i == m) {
        if(valid(mask, n)) {
            return 1;
        }
        else return 0;
    }
    if(dp[i][mask] != -1) return dp[i][mask];
    vector<ll> res;
    makeNext(mask, 0, 0, n, res);
    ll count = 0;
    for(auto x: res) {
        count = add(count, rec(x, i + 1, m, n));
    }
    dp[i][mask] = count;
    return count;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    mset(dp, -1);
    cout<<rec(0, 1, m, n)<<endl;
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




