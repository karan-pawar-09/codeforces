/*
author:Karan
created:13.06.2021 21:55:14
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const ll mod=(ll)1e9+7;

ll power(long long x, unsigned ll y, ll mod) {
    ll res = 1; 
    x = x % mod;   
    if (x == 0) return 0;  
    while (y > 0) {        
        if (y & 1)
            res = (res*x) % mod; 
        y = y>>1;
        x = (x*x) % mod;
    }
    return res;
}

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
        vector<pair<ll,ll>> arr(n);
        for(ll i=0;i<n;i++) {
            cin>>arr[i].first;
            arr[i].first--;
        }
        for(ll i=0;i<n;i++) {
            cin>>arr[i].second;
            arr[i].second--;
        }
        sort(all(arr));
        ll ans=0;
        vector<bool> visited(n,false);
        for(ll i=0;i<n;i++) {
            ll j=i;
            if(!visited[i]) {     
                visited[i]=true;           
                ll j=arr[i].second;
                while(!visited[j]) {
                    visited[j]=true;
                    j=arr[j].second;
                }
                ans++;
            }
        }
        ans=power(2,ans,mod);
        cout<<ans<<endl;
    }
}