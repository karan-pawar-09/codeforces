#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

static ll mod=(ll)1e9+7;
ll n,k;
vector<vector<vector<ll>>> dp;

int solve(int curr, int k, int dir) {
    if (k == 1) {
        return 1;
    }

    if (dp[curr][k][dir] != -1) {
        return dp[curr][k][dir];
    }

    int ans = 2;  // me and my copy

    if (dir == 1) {
        if (curr < n)
            ans += solve(curr + 1, k, dir) - 1;

        ans %= mod;

        if (curr > 1)
            ans += solve(curr - 1, k - 1, 1 - dir) - 1;

        ans %= mod;
        dp[curr][k][dir] = ans;
    } else {
        if (curr > 1)
            ans += solve(curr - 1, k, dir) - 1;

        ans %= mod;

        if (curr < n)
            ans += solve(curr + 1, k - 1, 1 - dir) - 1;

        ans %= mod;
        dp[curr][k][dir] = ans;
    }

    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--) {       
        cin>>n>>k;
        dp.resize(n+5,vector<vector<ll>>(k+5,vector<ll>(2,-1)));
        ll c= solve(1,k,1);
        cout<<c<<endl;
    }
}