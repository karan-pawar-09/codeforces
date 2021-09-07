/*
author:Karan
created:13.08.2021 13:05:04
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
        ll n,p,k;
        cin>>n>>p>>k;
        ll ans= 0;
        ll rem= p%k;
        ll res= (n-1)%k+1;
        for (ll i=rem;i<n;i+=k) {
            ans++;
            if (i==p) break;
        } 
        if (rem>res) {
            ans+=res*(((n-1)/k)+1)+(rem-res)*((n-1)/k);
        }
        else {
            ans+=(((n-1)/k)+1)*(rem);
        }        
        cout <<ans<<endl;
    }
}


