/*
    author:Karan
    created:06.07.2023 12:27:34
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

ll calc(vector<ll>& ar, ll n, ll m) {
    ll zz = ar[0];
    ll zr = ar[1];
    ll zc = ar[2];
    // cout << n << " " << m << endl;
    // cout << zz << " " << zr << " " << zc << endl;
    ll a = (m - 1) * (zr - zz);
    ll b = (n - 1) * (zc - zz);
    ll c = (n - 1) * (m - 1) * (max(zr, zc) - zz);
    // cout << a << " " << b << " " << c << endl;
    return a + b + c;
}

ll calc1(vector<ll>& ar, ll n, ll m) {
    ll zz = ar[0];
    ll zr = ar[1];
    ll zc = ar[2];
    // cout << n << " " << m << endl;
    // cout << zz << " " << zr << " " << zc << endl;
    ll ans = (m - 1) * (zz - zr);
    ans += (n - 1) * (zz - zc);
    ans += (n - 1) * (m - 1) * (zz - (min(zr, zc)));
    return ans;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> b(n * m);
    for (ll i = 0; i < n * m; i++) {
        cin >> b[i];
    }
    sort(all(b));
    vector<ll> ar;
    ar.push_back(b[0]);
    ar.push_back(b[n * m - 1]);
    ar.push_back(b[n * m - 2]);
    ll res = calc(ar, n, m);
    ar.clear();
    ar.push_back(b[0]);
    ar.push_back(b[n * m - 2]);
    ar.push_back(b[n * m - 1]);
    res = max(res, calc(ar, n, m));
    ar.clear();
    ar.push_back(b[n * m - 1]);
    ar.push_back(b[0]);
    ar.push_back(b[1]);
    res = max(res, calc1(ar, n, m));
    ar.clear();
    ar.push_back(b[n * m - 1]);
    ar.push_back(b[1]);
    ar.push_back(b[0]);
    res = max(res, calc1(ar, n, m));
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