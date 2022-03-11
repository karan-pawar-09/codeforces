/*
    author:Karan
    created:22.02.2022 20:45:40
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

const ll inf=1e18+10;

void solve() {
    ll n,x;
    cin>>n>>x;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    vector<ll> msum(n+1,-inf);
    ll res=0;
    for(ll i=0;i<n;i++) {
        ll sum=0;
        for(ll j=i;j<n;j++) {
            sum+=arr[j];
            msum[j-i+1]=max(msum[j-i+1],sum);
            res=max(res,msum[j-i+1]);
        }
    }
    cout<<res<<" ";
    vector<ll> ssum(n+1);
    ssum[n]=msum[n]; 
    for(ll i=n-1;i>0;i--) {
        ssum[i]=max(ssum[i+1],msum[i]);
    }
    ll prev=max(msum[n],0LL);
    for(ll i=1;i<=n;i++) {
        cout<<max(prev,ssum[i]+(x*i))<<" ";
        prev=max(prev,ssum[i]+(x*i));
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