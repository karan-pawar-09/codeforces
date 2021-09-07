/*
author:Karan
created:02.09.2021 20:31:57
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll x,y;
    cin>>x>>y;
    vector<ll> left(n),right(n);
    for(ll i=0;i<n;i++) {
        if(s[i]=='W') {
            left[i]=0;
        }
        else if(s[i]=='E') {
            left[i]=min(x,y)*2;
        }
        else if(s[i]=='N') {
            left[i]=min(y,3*x);
        }
        else {
            left[i]=min(3*y,x);
        }
    }
    for(ll i=0;i<n;i++) {
        if(s[i]=='E') {
            right[i]=0;
        }
        else if(s[i]=='W') {
            right[i]=min(x,y)*2;
        }
        else if(s[i]=='S') {
            right[i]=min(y,3*x);
        }
        else {
            right[i]=min(3*y,x);
        }
    }
  
    for(ll i=1;i<n;i++) {
        right[i]+=right[i-1];
    }
    for(ll i=n-2;i>=0;i--) {
        left[i]+=left[i+1];
    }
    ll ans=left[0];
    ans=min(ans,right[n-1]);

    for(ll i=1;i<n;i++) {
        ans=min(ans,right[i-1]+left[i]);
    }
    cout<<ans<<endl;
} 

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        solve();
    }
}