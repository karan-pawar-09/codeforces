/*
author:Karan
created:26.06.2021 18:05:17
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
    const ll mod=(ll)1e9+7;
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    ll k=0;
    ll sum=0;
    vector<ll> ans;
    for(ll i=0;i<n;i++) {
        k++;
        sum+=arr[i];
        if(sum%k==0) {

        }
        else {
            ans.push_back(k-1);
            k=0;
            sum=0;
        }
    }
    if(k!=0) {
        ans.push_back(k-1);
    }
    ll kk=0;
    for(ll i=0;i<ans.size();i++) {
        ll a=(power(2,n,mod)%mod-1%mod)%mod;
        a=(a*a)%mod;
        kk+=a;
    }
    cout<<kk<<endl;
}