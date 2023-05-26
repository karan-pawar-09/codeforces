/*
    author:Karan
    created:24.01.2023 20:11:03
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
    ll n = 4;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    ll time = 0;
    ll total = 0;
    total += arr[0];
    time += arr[0];
    if(arr[1] > arr[2]) {
        swap(arr[1], arr[2]);
    }
    arr[2] -= arr[1];
    if(total >= 1) {
        ll temp = arr[1] * 2;
        time += temp;
    } else {
        time += 1;
        total = -1;
    }
    
    if(arr[2] <= total) {
        time += arr[2];
        total -= arr[2];
    } else {
        time += total + 1;
        total = -1;
    }
    if(arr[3] <= total) {
        time += arr[3];
        total -= arr[3];
    } else {
        time += total +1;
        total = -1;
    }
    cout<<time<<endl;

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