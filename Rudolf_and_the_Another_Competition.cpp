/*
    author:Karan
    created:07.07.2023 20:22:17
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

bool comp(pair<ll, pair<ll, ll>>& a, pair<ll, pair<ll, ll>>& b) {
    if (a.first > b.first) {
        return true;
    }
    else if (a.first < b.first) {
        return false;
    }
    else {
        if (a.second.first < b.second.first) {
            return true;
        }
        else if (a.second.first > b.second.first) {
            return false;
        }
        else {
            return a.second.second < b.second.second;
        }
    }
}
void solve() {
    ll n, m, h;
    cin >> n >> m >> h;
    vector<vector<ll>> arr(n, vector<ll>(m));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (ll i = 0; i < n; i++) {
        sort(all(arr[i]));
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = 1; j < m; j++) {
            arr[i][j] += arr[i][j - 1];
        }
    }
    vector<pair<ll, pair<ll, ll>>> ar;
    for (ll i = 0; i < n; i++) {
        ll time = 0;
        ll count = 0;
        for (ll j = 0; j < m; j++) {
            if (arr[i][j] <= h) {
                time += arr[i][j];
                count++;
            }
            else {
                break;
            }
        }
        ar.push_back({ count, {time, i} });
    }
    sort(all(ar), comp);
    for (ll i = 0; i < n; i++) {
        if (ar[i].second.second == 0) {
            cout << i + 1 << endl;
            return;
        }
    }
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