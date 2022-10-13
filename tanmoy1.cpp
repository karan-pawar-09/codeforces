/*
    author:Karan
    created:04.08.2022 12:45:39
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

ll getMaxAgg(vector<ll> tempChange) {
    ll n = tempChange.size();
    vector<ll> pre(n), post(n);
    pre[0]=tempChange[0];
    post[n-1] = tempChange[n-1];
    for(ll i=1;i<n;i++) {
        pre[i] = pre[i-1]+tempChange[i];
    }
    for(ll i=n-2;i>=0;i--) {
        post[i] = post [i+1]+tempChange[i];
    }
    ll ans = -1e18+10;
    for(ll i=0;i<n;i++) {
        ans = max(ans, max(pre[i],post[i]));  
    }
    return ans;
}
void solve() {
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<getMaxAgg(arr)<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}