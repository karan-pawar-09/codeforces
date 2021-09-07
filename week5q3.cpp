/*
author:Karan
created:21.06.2021 22:36:41
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
    string s,t;
    cin>>s>>t;
    ll n=s.size();
    ll m=t.size();
    vector<vector<ll>> arr(n+1,vector<ll>(m+1,0));
    for(ll i=0;i<=n;i++) {
        arr[i][0]=i;
    }   
    for(ll i=0;i<=m;i++) {
        arr[0][i]=i;
    }
    for(ll i=1;i<=n;i++) {
        for(ll j=1;j<=m;j++) {
            if(s[i-1]==t[j-1]) {
                arr[i][j]=arr[i-1][j-1];
            }
            else {
                arr[i][j]=min({arr[i-1][j]+1,arr[i][j-1]+1,arr[i-1][j-1]+1});
            }
        }
    }
    cout<<arr[n][m]<<endl;
}