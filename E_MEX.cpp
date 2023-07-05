/*
    author:Karan
    created:01.07.2023 18:10:27
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

ll countMex(ll a, ll b, ll c) {
    set<ll> st;
    for (ll i = 0; i < 4; i++) {
        st.insert(i);
    }
    st.erase(a);
    st.erase(b);
    st.erase(c);
    return *st.begin();
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    string s;
    cin >> s;
    vector<ll> X(3, 0);
    vector<vector<ll>> E(3, vector<ll>(3, 0));
    ll res = 0;
    for (ll i = n - 1; i >= 0; i--) {
        if (s[i] == 'X') {
            X[arr[i]]++;
        }
        else if (s[i] == 'E') {
            for (ll j = 0; j < 3; j++) {
                E[arr[i]][j] += X[j];
            }
        }
        else {
            ll temp = 0;
            for (ll j = 0; j < 3; j++) {
                for (ll k = 0; k < 3; k++) {
                    ll p = countMex(arr[i], j, k);
                    temp += p * (E[j][k]);
                }
            }
            res += temp;
        }

    }
    cout << res << endl;
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