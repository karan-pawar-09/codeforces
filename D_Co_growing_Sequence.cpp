/*
author:Karan
created:11.07.2021 12:55:44
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
        vector<ll> ans(n,0);
        for(ll i=0;i<n;i++) {
            cin>>arr[i];
        }
        for(ll i=0;i<n-1;i++) {
            vector<ll> k(33,0);
            ll no=0;
            for(ll j=0;j<32;j++) {
                ll temp=(1<<j);
                if(arr[i]&temp) {
                    if(arr[i+1]&temp) {

                    }
                    else {
                        k[j]=1;
                    }
                }
                no+=k[j]*temp;
            }
            ll neww=arr[i+1]^no;
            arr[i+1]=neww;
            ans[i+1]=no;
        }
        for(ll i=0;i<n;i++) {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}