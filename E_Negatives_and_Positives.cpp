/*
    author:Karan
    created:03.02.2023 20:20:23
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
    ll negs = 0;
    bool zero = false;
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        if(arr[i] <= 0) {
            if(arr[i] < 0) {
                negs++;
            } else {
                zero = true;
            }
        }
        arr[i] = abs(arr[i]);
    }
    sort(all(arr));
    ll sum = 0;
    for(auto x: arr) {
        sum += abs(x);
    }
    if(negs%2==0 || zero) {
        cout<<sum<<endl;
    } else {
        cout<<sum - 2*arr[0]<<endl;
    }
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