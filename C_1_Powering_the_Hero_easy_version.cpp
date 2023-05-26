/*
    author:Karan
    created:03.03.2023 14:21:25
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
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    multiset<ll, greater<ll>> st;
    ll ans = 0;
    for(ll i=0;i<n;i++) {
        if(arr[i] == 0) {
            if(st.size()) {
                ans += *st.begin();
                st.erase(st.begin());
            }
        } else {
            st.insert(arr[i]);
        }
    }
    cout<<ans<<endl;
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