/*
author:Karan
created:20.06.2021 17:06:25
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll n;
    cin>>n;
    vector<pair<ll,ll>> arr(n);
    ll sum=0;
    for(ll i=0;i<n;i++) {
        cin>>arr[i].second>>arr[i].first;
        sum+=arr[i].second;
    }
    sort(all(arr));
    ll l=0;
    ll r=n-1;
    ll total=0;
    ll ans=0;
    while(l<=r) {
        if(total>=arr[l].first) {
            ans+=arr[l].second;
            total+=arr[l].second;
            l++;
        }
        else {
            ll temp=min(arr[r].second,arr[l].first-total);
            arr[r].second-=temp;
            total+=temp;
            ans+=2*temp;
            if(arr[r].second==0) r--;
        }
    }
    cout<<ans<<endl;
}