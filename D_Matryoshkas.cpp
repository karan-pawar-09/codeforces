/*
    author:Karan
    created:27.01.2023 20:49:36
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
    vector<ll> arr(n);
    multiset<ll> st;
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        st.insert(arr[i]);
    }
    ll ans = 0;
    while(st.size()) {
        ll mini = *st.begin();
        st.erase(st.begin());
        while(st.count(mini+1)) {
            st.erase(st.find(mini+1));
            mini += 1;
        }
        ans++;
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