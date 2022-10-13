/*
    author:Karan
    created:11.03.2022 16:06:54
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

void solve() {
    ll n;
    cin >> n;
    queue<ll> q;
    for (ll i = 0;i < n;i++) {
        ll a;
        cin >> a;
        q.push(a);
    }
    vector<ll> ans;
    for (ll i = n;i >= 1;i--) {
        vector<ll> temp;
        ll res = 0;
        while (q.front() != i) {
            temp.push_back(q.front());
            q.pop();
            res++;
        }
        res++;
        q.pop();
        ans.push_back(res % i);
        for (ll x : temp) {
            q.push(x);
        }
    }
    reverse(all(ans));
    for (auto x : ans) cout << x << " ";
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}