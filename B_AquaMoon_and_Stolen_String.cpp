/*
author:Karan
created:13.07.2021 11:09:41
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
        ll n,m;
        cin>>n>>m;
        vector<string> q(n);
        vector<string> r(n-1);
        vector<vector<ll>> freq(m,vector<ll> (30,0));
        for(ll i=0;i<n;i++) {
            cin>>q[i];
        }
        for(ll i=0;i<n-1;i++) {
            cin>>r[i];
            for(ll j=0;j<m;j++) {
                freq[j][r[i][j]-'a']++;
            }
        }
        string ans;
        for(ll i=0;i<n;i++) {
            ll temp=0;
            for(ll j=0;j<m;j++) {
                if(freq[j][q[i][j]-'a']>0) {                    
                    temp++;
                }
                freq[j][q[i][j]-'a']--;
            }
        }
        for(ll i=0;i<m;i++) {
            for(ll j=0;j<26;j++) {
                if(freq[i][j]==-1) {
                    ans.push_back('a'+j);
                }
            }

        }
        cout<<ans<<endl;
        cout.flush();
    }
}