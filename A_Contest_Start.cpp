/*
author:Karan
created:20.06.2021 15:35:18
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
    ll k;
    cin>>k;
    while(k--) {
        ll n,x,t;
        cin>>n>>x>>t;
        ll length=min(n-1,t/x);
        ll ans=(length)*(n-length);
        ans+=((length)*(length-1))/2;
        cout<<max(ans,0LL)<<endl;
    }
}