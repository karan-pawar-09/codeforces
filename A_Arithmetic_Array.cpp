/*
author:Karan
created:18.06.2021 20:08:08
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
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        vector<ll> arr(n);
        ll sum=0;
        for(ll i=0;i<n;i++) {
            cin>>arr[i];
            sum+=arr[i];
        }
        int avg=sum/n;
        if(avg>=1) {
            cout<<max(0LL,sum-n)<<endl;
        }
        else {
            cout<<1<<endl;
        }
    }
}