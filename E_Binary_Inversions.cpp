/*
    author:Karan
    created:22.11.2022 18:51:54
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
    vector<ll> ar(n);
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>ar[i];
    }
    arr = ar;
    vector<ll> pre(n, 0);
    vector<ll> post(n, 0);
    
    for(ll i=0;i<n;i++) {
        if(arr[i]==0) {
            arr[i] = 1;
            break;
        }
    }
    ll ans1 = 0;
    ll ans2 = 0;
    ll temp = 0;
    for(ll i=n-1;i>=0;i--) {
        if(arr[i]==1) {
            ans1 += temp;
        } else {
            temp++;
        }
    }
    arr = ar;
    for(ll i=n-1;i>=0;i--) {
        if(arr[i]==1) {
            arr[i] = 0;
            break;
        }
    }
    temp = 0;
    for(ll i=n-1;i>=0;i--) {
        if(arr[i]==1) {
            ans2 += temp;
        } else {
            temp++;
        }
    }
    ll ans3 = 0;
    arr = ar;
    temp = 0;
    for(ll i=n-1;i>=0;i--) {
        if(arr[i]==1) {
            ans3 += temp;
        } else {
            temp++;
        }
    }
    cout<<max({ans1, ans2, ans3})<<endl;
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