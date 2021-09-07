/*
author:Karan
created:27.06.2021 13:53:56
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

ll binarysearch(ll a,vector<ll> &arr,ll n) {
    ll l=-1;
    ll r=n-1;
    while(l+1<r) {
        ll m=l+(r-l)/2;
        if(arr[m]>=a) {
            r=m;
        }
        else {
            l=m;
        }
    }
    return r;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    vector<ll> ans;
    ans.push_back(arr[0]);
    for(ll i=1;i<n;i++) {
        if(arr[i]>ans.back()) {
            ans.push_back(arr[i]);
        }
        else {
            if(ans.back()!=arr[i]) {
                ans[binarysearch(arr[i],ans,ans.size())]=arr[i];
            }
        }
    }
    cout<<ans.size()<<endl;
}