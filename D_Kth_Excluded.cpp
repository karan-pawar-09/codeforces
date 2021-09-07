/*
author:Karan
created:14.06.2021 12:50:12
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
pair<ll,ll> index(ll a,vector<ll>&arr,vector<ll>&finding) {
    ll l=0;
    ll r=arr.size();
    while(l+1<r) {
        ll m=l+(r-l)/2;
        if(a>=finding[m]) {
            l=m;
        }
        else {
            r=m;
        }
    }
    return {finding[l],arr[l]+1};
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll n,q;
    cin>>n>>q;
    vector<ll> arr(n+1);
    arr[0]=-1;
    for(ll i=1;i<=n;i++) {
        cin>>arr[i];
    }  
    n=n+1;
    vector<ll> finding(n);
    finding[0]=0;
    ll kk=0;
    for(ll i=1;i<n;i++) {
        finding[i]=arr[i]-kk;
        kk++;
    }
    while(q--) {
        ll a;
        cin>>a;
        pair<ll,ll> p=index(a,arr,finding);
        cout<<p.second+(a-p.first)<<endl;
    }
}