/*
author:Karan
created:11.07.2021 13:18:44
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const ll inf=(ll)1e12+7;

void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll> ans(n+2);
    vector<ll> arr(k);
    vector<ll> t(k);
    vector<ll> left(n+2,inf);
    vector<ll> right(n+2,inf);
    vector<bool> ac(n+2,false);
    for(ll i=0;i<k;i++) {
        cin>>arr[i];
        ac[arr[i]]=true;
    }
  
    for(ll i=0;i<k;i++) {
        cin>>t[i];
        left[arr[i]]=t[i];
        right[arr[i]]=t[i];
    }
    for(ll i=2;i<=n;i++) {
        if(!ac[i]) {
            left[i]=min(left[i-1]+1,left[i-2]+2);
        }
        else {
            left[i]=min(left[i],left[i-1]+1);
        }
    }
    for(ll i=n-1;i>=0;i--) {
        if(!ac[i]) {
            right[i]=min(right[i+1]+1,right[i+2]+2);
        }
        else {
            right[i]=min(right[i],right[i+1]+1);
        }
    }
    for(ll i=1;i<=n;i++) {
        ans[i]=min(left[i],right[i]);
    }
    for(ll i=1;i<=n;i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll q;
    cin>>q;
    while(q--) {
        solve();
    }
}