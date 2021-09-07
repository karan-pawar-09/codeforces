/*
author:Karan
created:30.05.2021 20:49:46
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    vector<vector<ll>> arr(n,vector<ll>(n));
    for(ll i=0;i<n;i++) {
        for(ll j=0;j<n;j++) {
            cin>>arr[i][j];
        }
    }
    ll pp=(k*k/2)+1;
    ll ans=(ll)1e18;
    for(int i=0;i<=n-k;i++) {
        for(int j=0;j<=n-k;j++) {
            vector<ll> ar;
            for(int a=i;a<i+k;a++) {
                for(int b=j;b<j+k;b++) {
                    ar.push_back(arr[a][b]);
                }
            }
            int z=0;
            sort(all(ar),greater<ll>());
            ans=min(ans,ar[(int)pp-1]);
        }
    }
    cout<<ans<<endl;
}