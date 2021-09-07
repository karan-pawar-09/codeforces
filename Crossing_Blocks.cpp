/*
author:Karan
created:28.08.2021 19:46:06
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    vector<ll> maxi(n);
    ll mx=n-1;
    maxi[n-1]=n+1;
    ll mxval=arr[n-1];
    for(ll i=n-2;i>=0;i--) {
        maxi[i]=mx;
        if(arr[i]>mxval) {
            mxval=arr[i];
            mx=i;
        }
    }
    vector<ll> allno;
    for(ll i=0;i<n;i=maxi[i]) {
        allno.push_back(arr[i]);
    }
    bool ans=true;
    for(ll i=1;i<allno.size();i++) {
        if(allno[i]>allno[i-1]) {
            ans=false;
            break;
        }
    }
    if(ans) {
        cout<<allno.size()-1<<endl;
    }
    else {
        cout<<-1<<endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        solve();
    }
}