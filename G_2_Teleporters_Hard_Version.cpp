/*
    author:Karan
    created:03.02.2023 20:47:44
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


bool comp2(pair<pair<ll, ll>, ll> &a, pair<pair<ll, ll>, ll> &b) {
    return min(a.first.first, a.first.second) < min(b.first.first, b.first.second);
}

ll binarysearch(ll x, vector<pair<pair<ll, ll>, ll>> &arr, ll indx) {
    if (x < 0) {
        return -1;
    }
    ll l = 0;
    ll r = arr.size();
    while (l + 1 < r) {
        ll m = l + (r - l) / 2;
        if (m >= indx) {
            if (arr[m].second - min(arr[indx].first.first, arr[indx].first.second) <= x) {
                l = m;
            }
            else {
                r = m;
            }
        }
        else {
            if (arr[m].second <= x) {
                l = m;
            }
            else {
                r = m;
            }
        }
    }
    if (l >= indx) {
        if (arr[l].second - min(arr[indx].first.first, arr[indx].first.second) <= x) {
            return l;
        }
        else {
            return 0;
        }
    }
    else {
        if (arr[l].second <= x) {
            return l+1;
        }
        else {
            return 0;
        }
    }
}

void solve() {
    ll n, c;
    cin >> n >> c;
    vector<pair<ll, bool>> arr(n);
    vector<pair<pair<ll, ll>, ll>> res(n);
    for (ll i = 0;i < n;i++) {
        cin >> arr[i].first;
        res[i].second = i;
        res[i].first.first = arr[i].first + i + 1;
        res[i].first.second = arr[i].first + n - i;
    }
    sort(all(res), comp2);
    res[0].second = min(res[0].first.first, res[0].first.second);
    for (ll i = 1;i < n;i++) {
        res[i].second = res[i - 1].second + min(res[i].first.first, res[i].first.second);
    }
    ll maxi = 0;
    for (ll i = 0;i < n;i++) {
        maxi = max(maxi, 1 + binarysearch(c - res[i].first.first, res, i));
    }
    cout << maxi << endl;
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