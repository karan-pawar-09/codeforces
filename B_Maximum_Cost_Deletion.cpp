/*
author:Karan
created:16.07.2021 15:11:26
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
        ll n,a,b;
        cin>>n>>a>>b;
        string s;
        cin>>s;
        ll ans=0;
        if(b>=0) {
            ans+=(n*a)+(n*b);
        }
        else {
            ll ones=0;
            ll twos=0;
            for(ll i=0;i<n-1;i++) {
                if(s[i]=='0') {
                    if(s[i+1]=='1') {
                        ones++;
                    }
                }
                if(s[i]=='1') {
                    if(s[i+1]=='0') {
                        twos++;
                    }
                }
            }
            if(s[n-1]=='0') {
                ones++;
            }
            else {
                twos++;
            }
            ll res=min(ones,twos)+1;
            ans=(n*a)+(res*b);
        }
        cout<<ans<<endl;
    }
}