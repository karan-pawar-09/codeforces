/*
    author:Karan
    created:09.03.2022 20:26:26
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

ll diff(vector<ll>& a, vector<ll>& b) {
    ll ares = 0;
    ll bres = 0;
    for (auto x : a) {
        ares += x;
    }
    for (auto x : b) {
        bres += x;
    }
    return ares - bres;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    vector<ll> pos;
    vector<ll> neg;
    for (ll i = 0;i < n;i++) {
        cin >> arr[i];
        if (i % 2) {
            neg.push_back(abs(arr[i]));
        }
        else {
            pos.push_back(abs(arr[i]));
        }
    }
    sort(all(pos));
    sort(all(neg));
    ll res = diff(pos, neg);
    swap(pos[0], neg[neg.size() - 1]);
    res = max(res, diff(pos, neg));
    swap(pos[0], neg[neg.size() - 1]);
    swap(pos[pos.size() - 1], neg[0]);
    res = max(res, diff(pos, neg));
    cout << res << endl;
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