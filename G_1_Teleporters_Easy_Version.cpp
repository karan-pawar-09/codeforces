/*
    author:Karan
    created:03.02.2023 20:25:35
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
    ll n, c;
    cin>>n>>c;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        arr[i] += i+1;
    }
    sort(all(arr));
    ll index = 0;
    for(ll i=0;i<n;i++) {
        if(c >= arr[i]) {
            c -= arr[i];
            index++;
        } else {
            break;
        }
    }
    cout<<index<<endl;
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