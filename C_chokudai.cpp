/*
author:Karan
created:26.07.2021 16:25:28
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const ll mod=1e9+7;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    string s;
    cin>>s;
    ll n=s.size();
    vector<ll> freq(128,0);
    for(ll i=0;i<n;i++) {
        if(s[i]=='c') {
            freq['c']++;
        }
        else if(s[i]=='h') {
            freq['h']=(freq['h']%mod+freq['c']%mod)%mod;
        }
        else if(s[i]=='o') {
            freq['o']=(freq['o']%mod+freq['h']%mod)%mod;
        }
        else if(s[i]=='k') {
            freq['k']=(freq['k']%mod+freq['o']%mod)%mod;
        }
        else if(s[i]=='u') {
            freq['u']=(freq['u']%mod+freq['k']%mod)%mod;
        }
        else if(s[i]=='d') {
            freq['d']=(freq['d']%mod+freq['u']%mod)%mod;
        }
        else if(s[i]=='a') {
            freq['a']=(freq['a']%mod+freq['d']%mod)%mod;
        }
        else if(s[i]=='i') {
            freq['i']=(freq['i']%mod+freq['a']%mod)%mod;
        }
    }
    cout<<freq['i']%mod<<endl;
}