/*
    author:Karan
    created:10.02.2022 15:48:30
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

ll binarysearch(ll x,ll n) {
    ll l=1;
    ll r=1e9+7;
    while(l+1<r) {
        ll m=l+(r-l)/2;
        if(((m*m)-m)<=(2*(x-n))) {
            l=m;
        } else {
            r=m;
        }
    }
    return l;
}

void solve() {
    ll n,k;
    cin>>n>>k;
    ll x=binarysearch(k,n);
    vector<ll> arr;
    for(ll i=0;i<x;i++) {
        arr.push_back(i+1);
    }
    ll rem=k-(x*(x+1))/2;
    ll f=n-rem;
    f--;
    f=max(f,0LL);
    if(arr.size()<n)
        arr.push_back(arr[f]);
    for(ll i=x+1;i<n;i++) {        
        arr.push_back(arr.back());        
    }
    for(auto x:arr) {
        cout<<x<<" ";
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
