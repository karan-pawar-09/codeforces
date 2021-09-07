/*
author:Karan
created:10.07.2021 17:31:44
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
    bool ans=true;
    ll n,x;
    cin>>n>>x;
    ll sum=0;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        if(i%2==1) {
            sum+=arr[i]-1;
        }
        else {
            sum+=arr[i];
        }
    }
    if(sum<=x) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
}