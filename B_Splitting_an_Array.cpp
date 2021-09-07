/*
author:Karan
created:21.06.2021 13:11:15
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

bool isGood(ll x,vector<ll> arr,ll k) {
    ll no=0;
    ll sum=0;
    bool single = true;
    for(ll i=0;i<arr.size();i++) {
        if(arr[i]>x) {
            single=false;
        }
        if(sum+arr[i]<=x) {
            sum+=arr[i];
        }
        else {
            sum=arr[i];
            no++;
        }
    }
        no++;
    
    return (no<=k&&single);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    ll l=0;
    ll r=(ll)1e18;
    while(r>l+1) {
        ll m=l+(r-l)/2;
        if(isGood(m,arr,k)) {
            r=m;
        }
        else {
            l=m;
        }
    }
    cout<<r<<endl;

}   