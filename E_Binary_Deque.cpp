/*
    author:Karan
    created:14.06.2022 20:58:27
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

const ll inf = 1e18+7;
const ll mx = 1e6+10;
ll arr[mx];
ll post[mx];
ll binarySearch(ll x, ll n) {
    ll r=n+2;
    ll l=0;
    while(l+1 < r) {
        ll m=l+(r-l)/2;
        if(post[m]>=x) {
            l=m;
        }
        else {
            r=m;
        }
    }
    if(post[l]!= x) {
        return -1;
    } else {
        return l;
    }
}
void solve() {
    ll n,s;
    cin>>n>>s;
    for(ll i=0;i<n+100;i++) {
        post[i]=0;
        arr[i]=0;
    }
    ll ksum=0;
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        ksum+=arr[i];
    }
    s=ksum-s;
    if(s==0) {
        cout<<0<<endl;
        return;
    }
    post[n]=arr[n-1];
    for(ll i=n-2;i>=0;i--) {
        post[i+1] = post[i+2]+arr[i];
    }
    post[0]=inf;
    ll sum=0;
    ll ans = inf;
    {
        ll r=binarySearch(s,n);
        if(r>=0 && r!=-1) {
            ans=min(ans,(n-r+1));
        }
    }
    for(ll i=0;i<n;i++) {
        sum+=arr[i];
        ll r=binarySearch(s-sum,n);
        if(r>i && r!=-1) {
            ans=min(ans,i+1+(n-r+1));
        }
    }
    if(ans==inf) {
        cout<<-1<<endl;
    } else {
        cout<<ans<<endl;
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