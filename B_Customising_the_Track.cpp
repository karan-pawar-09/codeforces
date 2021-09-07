/*
author:Karan
created:07.07.2021 20:15:33
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
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        vector<ll> arr(n);
        ll sum=0;
        for(ll i=0;i<n;i++)  {
            cin>>arr[i];
            sum+=arr[i];
        }
        ll avg=sum/n;
        ll diff=abs(avg*n-sum);
        cout<<diff*(n-diff)<<endl;
    }
}