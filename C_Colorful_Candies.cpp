/*
author:Karan
created:17.07.2021 17:36:29
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll n,k;
    cin>>n>>k;
    vector<ll> arr(n);
    map<ll,ll> ans;
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        if(i<k) {
            ans[arr[i]]++;
        }
    }
    ll res=ans.size();
    for(ll i=k;i<n;i++) {
        ans[arr[i-k]]--;
        if(ans[arr[i-k]]<=0) {
            ans.erase(arr[i-k]);
        }
        ans[arr[i]]++;
        res=max(res,(ll)ans.size());
    }
    cout<<res<<endl;
}