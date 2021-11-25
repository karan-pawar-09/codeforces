/*
    author:Karan
    created:21.11.2021 21:17:19
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

const ll mx=3e3+10;
ll n;
ll arr[mx];

ll binarysearch(ll i,ll s,ll t) {
    ll l=s;
    ll r=t+1;
    while(l+1<r) {
        ll m=l+(r-l)/2;
        if((2*arr[m])<=i) {
            l=m;
        }
        else {
            r=m;
        }
    }
    return l;
}

void solve() {
    cin>>n;
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    ll ans=0;
    for(ll i=0;i<n;i++) {
        for(ll j=i+2;j<n;j++) {            
                ll x=binarysearch(arr[i]+arr[j],i,j);
                ll xx=0;
                ll g=0;
                while(x<j and g<3) {
                    xx=max(xx,(arr[j]-arr[x])*(arr[x]-arr[i]));
                    x++;
                    g++;
                }
                ans+=xx;
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