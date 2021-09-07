/*
author:Karan
created:12.06.2021 17:27:08
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
ll binarysearch(ll a,vector<ll> &arr) {
    ll l=0;
    ll r=arr.size();
    while(l+1<r) {
        ll m=l+(r-l)/2;
        if(arr[m]<=a) {
            l=m;
        }
        else {
            r=m;
        }
    }
    return arr[l]==a?l:-1LL;
}
int main() {
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
    ll k;
    cin>>k;
    while(k--) {
        ll p;
        cin>>p;
        cout<<binarysearch(p,arr)<<" ";
    }
    cout<<endl;
}