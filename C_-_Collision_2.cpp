/*
    author:Karan
    created:14.03.2022 22:25:59
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

const ll inf = 1e18 + 10;
void solve() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    for (ll i = 0;i < n;i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    string s;
    cin >> s;
    map<ll, pair<ll, ll>>  col;
    for (ll i = 0;i < n;i++) {
        col[arr[i].second] = { inf,-inf };
    }
    for (ll i = 0;i < n;i++) {
        if (s[i] == 'R') {
            col[(ll)arr[i].second].first = min(col[(ll)arr[i].second].first, arr[i].first);
        }
        else {
            col[(ll)arr[i].second].second = max(col[(ll)arr[i].second].second, arr[i].first);
        }
    }
    bool ans = false;
    for (auto x : col) {
        if (x.second.first <= x.second.second) ans = true;
    }
    ans ? cout << "Yes" << endl : cout << "No" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t = 1;
    //cin>>t;
    while (t--) {
        solve();
    }
}