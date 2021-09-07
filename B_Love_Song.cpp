/*
author:Karan
created:20.06.2021 16:02:37
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
    ll n,q,a,b;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<vector<ll>> freq(n+1,vector<ll>(26,0));
    for(ll i=1;i<=n;i++) {
        for(ll j=0;j<26;j++) {
            freq[i][j]=freq[i-1][j];
        }
        freq[i][s[i-1]-'a']++;
    }
    while(q--) {
        cin>>a>>b;
        ll ans=0;
        for(ll i=0;i<26;i++) {
            ans+=(freq[b][i]-freq[a-1][i])*(i+1);
        }
        cout<<ans<<endl;
    }  
}