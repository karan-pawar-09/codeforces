/*
    author:Karan
    created:06.07.2023 20:19:30
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
    vector<ll> arr(n);
    ll p = -1;
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        if (p == -1) {
            p = arr[i];
        }
        else {
            p &= arr[i];
        }
    }
    if(p != 0) {
        cout<<1<<endl;
        return;
    }
    ll count = 0;
    ll andd = -1;
    for (ll i = 0; i < n; i++) {
        if (andd == -1) {
            andd = arr[i];
        }
        else {
            andd &= arr[i];
        }
        if (andd == p) {
            count++;
            andd = -1;
        }
    }
    cout << count << endl;
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