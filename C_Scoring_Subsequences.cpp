/*
    author:Karan
    created:04.03.2023 23:28:59
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

ll binarysearch(vector<ll> &arr, ll end) {
    ll l = -1;
    ll r = end;
    while(l+1 < r) {
        ll m = (l+r)/2;
        if(arr[m] >= (end - m +1)) {
            r = m;
        } else {
            l = m;
        }
    }
    return r;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    for(ll i=1;i<=n;i++) {
        cout<<i-binarysearch(arr,i-1)<<" ";
    }
    cout<<endl;
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