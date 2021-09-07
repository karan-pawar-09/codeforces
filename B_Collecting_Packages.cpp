/*
author:Karan
created:08.07.2021 22:55:15
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
        vector<pair<ll,ll>> arr(n);
        for(ll i=0;i<n;i++) {
            cin>>arr[i].first>>arr[i].second;
        }
        sort(all(arr));
        ll a=0;
        ll b=0;
        bool ans=true;
        string path;
        for(ll i=0;i<n;i++) {
            if(arr[i].second<b) {
                ans=false;
                break;
            }
            else{
                ll right=arr[i].first-a;
                ll up=arr[i].second-b;
                for(ll j=0;j<right;j++) path.push_back('R');
                for(ll j=0;j<up;j++) path.push_back('U');
                a+=right;
                b+=up;
            }
        }
        if(ans) {
            cout<<"YES"<<endl;
            cout<<path<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
}