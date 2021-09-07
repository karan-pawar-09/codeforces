/*
author:Karan
created:13.07.2021 12:00:27
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
        vector<ll> even(1e5+7,0);
        vector<ll> odd(1e5+7,0);
        for(ll i=0;i<n;i++) {
            cin>>arr[i];
            if(i%2) {
                odd[arr[i]]++;
            }
            else {
                even[arr[i]]++;
            }
        }
        sort(all(arr));
        bool ans=true;
        for(ll i=0;i<n;i++) {
            if(i%2) {
                odd[arr[i]]--;
            }
            else {
                even[arr[i]]--;
            }
        }    
        for(ll i=0;i<n;i++) {
            if(odd[arr[i]]!=0||even[arr[i]]!=0) {
                ans=false;
                break;
            }
        }    
        if(!ans) {
            cout<<"NO"<<endl;
        }
        else {
            cout<<"YES"<<endl;
        }
    }
}