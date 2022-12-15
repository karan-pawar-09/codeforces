/*
    author:Karan
    created:22.11.2022 19:39:48
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
    ll n, c, d;
    cin >> n >> c >> d;
    vector<ll> arr(n);
    ll sum = 0;
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(all(arr), greater<ll> ());
    vector<ll> pre(d+1);
    for(ll i = 0; i <= d; i++) {
        if(i<n) {
            sum += arr[i];
        }
        pre[i] = sum;
        if(sum >= c && (i+1)<=d) {
            cout<<"Infinity"<<endl;
            return;
        }
    }
    if(arr[0]*d < c) {
        cout<<"Impossible"<<endl;
        return;
    }
    ll ans = 0;
    for(ll i=0;i<d;i++) {
        ll no = i+1;
        ll dev = d/no;
        ll rem = d%no;
        ll total = pre[i]*dev;
        if(rem > 0) {
            total += pre[rem-1];
        }
        if(total>=c) {
            ans = i;
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