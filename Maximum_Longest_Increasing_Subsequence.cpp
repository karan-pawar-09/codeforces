/*
author:Karan
created:03.08.2021 18:49:58
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
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++) {
            cin>>arr[i];
        }
        vector<ll> ans;
        ans.push_back(arr[0]);
        ll maxi=1;
        ll answer=0;
        for(ll i=1;i<n;i++) {
            if(arr[i]>ans.back()) {
                ans.push_back(arr[i]);
            }
            else {
                if(ans.back()!=arr[i]) {
                    ll k=binarysearch(arr[i],ans,ans.size());
                    ans[k]=arr[i];
                }
            }
        }
        maxi=ans.size();
        ans.resize(0);
        ans.push_back(arr[0]);
        for(ll i=1;i<n;i++) {
            if(arr[i]>ans.back()) {
                ans.push_back(arr[i]);
            }
            else {
                if(ans.back()!=arr[i]) {
                    ll k=binarysearch(arr[i],ans,ans.size());
                    ans[k]=arr[i];
                }
            }
            if(ans.size()==maxi) {
                answer=max(answer,ans[maxi-1]-ans[0]);
            }
        }
        cout<<answer<<endl;
    }
}