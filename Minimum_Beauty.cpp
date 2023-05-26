/*
    author:Karan
    created:08.02.2023 20:10:34
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

ll binarysearch(vector<ll> &arr, ll start, ll end) {
    ll l = start+1;
    ll r = end;
    while(l+1 < r) {
        ll m = (l+r)/2;
        if((arr[m]*2) <= (arr[start]+arr[end])) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}
ll bs(vector<ll> &arr, ll start, ll end) {
    ll l = start;
    ll r = end-1;
    while(l+1 < r) {
        ll m = (l+r)/2;
        if((arr[m]*2) >= (arr[start]+arr[end])) {
            r = m;
        } else {
            l = m;
        }
    }
    return r;
}
void solve() {
    ll n;
    cin>>n;
    vector<ll> arr(n);
    multiset<ll> s;
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        s.insert(arr[i]);
    }
    sort(all(arr));
    ll ans = 1e18+10;
    for(ll i=0;i<n;i++) {
        for(ll j=i+2;j<n;j++) {
            ll k = arr[i] + arr[j];
            ll start = binarysearch(arr, i, j);

            if(start>i && start < j) {
                ans = min(ans, abs(k+arr[start] - (3*arr[start])));
            }
            ll endp = bs(arr, i, j);
            if(endp > i && endp < j) {
                ans = min(ans, abs(k+arr[endp] - (3*arr[endp])));
            }

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