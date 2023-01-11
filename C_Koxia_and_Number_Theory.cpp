/*
    author:Karan
    created:01.01.2023 11:00:25
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
    cin>>n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (a[i] == a[j]) {
          ok = false;
        }
      }
    }
    for (int p = 2; p <= n; p++) {
      vector<int> cnt(p);
      for (int i = 0; i < n; i++) {
        cnt[a[i] % p] += 1;
      }
      if (*min_element(cnt.begin(), cnt.end()) >= 2) {
        ok = false;
        break;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}


