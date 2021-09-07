/*
author:Karan
created:29.08.2021 16:00:33
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
        ll n,k;
        cin>>n>>k;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++) {
            cin>>arr[i];
        }
        sort(all(arr));
        for(ll i=0;i<n;i++) {
            if(arr[i]<0) {
                if(k>0) {
                    arr[i]=-arr[i];
                    k--;
                }
            }
        }
        sort(all(arr));
        ll sum=0;
        for(ll i=n-1;i>=0;i--) {
            if(arr[i]>0) {
                sum+=arr[i];
            }
            else {
                break;
            }
        }
        cout<<sum<<endl;
    }
}