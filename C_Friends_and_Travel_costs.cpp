/*
author:Karan
created:30.05.2021 20:21:39
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

bool sortbysec(const pair<ll,ll> &a,const pair<ll,ll> &b) {
    return (a.second > b.second);
}
bool sortbyfirc(const pair<ll,ll> &a,const pair<ll,ll> &b) {
    return (a.first < b.first);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    vector<pair<ll,ll>> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i].first>>arr[i].second;
    }
    sort(all(arr),sortbysec);
    sort(all(arr),sortbyfirc);
    ll ans=0;
    for(ll i=0;i<n;i++) {
        if(arr[i].first<=k+ans) {
            k-=(arr[i].first-ans);
            ans+=(arr[i].first-ans);            
            k+=arr[i].second;
        }
        else {
            ans+=k;
            k=0;
            break;
        }
    }
    if(k!=0) {
        ans+=k;
    }
    cout<<ans<<endl;
}