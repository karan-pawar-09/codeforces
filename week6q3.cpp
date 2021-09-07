/*
author:Karan
created:22.06.2021 22:22:45
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

ll result(ll a,ll b,char c) {
    if(c=='-') return a-b;
    if(c=='+') return a+b;
    return a*b;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    string s;
    cin>>s;
    vector<char> c;
    vector<ll> num;
    for(ll i=0;i<s.size();i++)  {
        if(s[i]=='-'||s[i]=='+'||s[i]=='*') {
            c.push_back(s[i]);
        }
        else {
            num.push_back(s[i]-'0');
        }
    } 
    ll k=c.size();
    ll n=num.size();
    vector<vector<ll>> mini(n+1,vector<ll> (n+1,(ll)1e18+7)); 
    vector<vector<ll>> maxi(n+1,vector<ll> (n+1,(ll)-1e18+7));
    for(ll i=1;i<=n;i++) {
        mini[i][i]=num[i-1];
        maxi[i][i]=num[i-1];
    }
    for(ll k=1;k<n;k++) {
        for(ll i=1;i<=n-k;i++) {
            ll j=i+k;
            for(ll l=i;l<j;l++) {
                ll aa=result(mini[i][l],mini[l+1][j],c[l-1]);
                ll bb=result(maxi[i][l],maxi[l+1][j],c[l-1]);
                ll cc=result(mini[i][l],maxi[l+1][j],c[l-1]);
                ll dd=result(maxi[i][l],mini[l+1][j],c[l-1]);
                mini[i][j]=min({mini[i][j],aa,bb,cc,dd});
                maxi[i][j]=max({maxi[i][j],aa,bb,cc,dd});
            }
        }
    }
    cout<<maxi[1][n]<<endl;
}