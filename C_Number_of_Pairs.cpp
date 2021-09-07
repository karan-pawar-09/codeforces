/*
author:Karan
created:10.06.2021 20:34:18
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
ll n;
vector<ll> arr;
ll lowerbound(ll a,ll x,ll i) {
    ll l=i;
    ll r=n;
    while(l+1<r) {
        ll m=l+(r-l)/2;
        if(a+arr[m]>x) {
            r=m;
        }
        else {
            l=m;
        }
    }
    return r;
}
ll upperbound(ll a,ll x,ll i) {
    ll l=i;
    ll r=n;
    while(l+1<r) {
        ll m=(l)+(r-l)/2;
        if(a+arr[m]>=x) {
            r=m;
        }
        else {
            l=m;
        }
    }
    return r;    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        ll l,r;
        cin>>n>>l>>r;
        arr.resize(n+2);
        arr[0]=(ll)-1e18+7;
        for(ll i=1;i<=n;i++) {
            cin>>arr[i];
        }
        arr[n+1]=(ll)1e18+7;
        n=n+2;
        sort(all(arr));
        ll ans=0;
        for(ll i=1;i<=n;i++) {
            if(arr[i]+arr[i]>r) {
                break;
            }
            if(arr[i]+arr[n-1]<l) {
                continue;
            }
            else {
                ans+=max(lowerbound(arr[i],r,i)-upperbound(arr[i],l,i),0LL);
            }
        }
        cout<<ans<<endl;
    }   
}