/*
authot:Karan
created:19.05.2021 16:11:35
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--) {
        ll n,k;
        cin>>n>>k;
        vector<ll> h(n);
        for(ll i=0;i<n;i++) {
            cin>>h[i];
        }
        bool ans=true;
        ll hightmin=h[0];
        ll hightmax=h[0];
        for(ll i=1;i<n;i++) {
            hightmax+=k-1;
            hightmin-=k-1;
            if(hightmin<h[i]) {
                hightmin=h[i];
            }
            if(hightmax<h[i]) {
                ans=false;
                break;
            }
            if(hightmin-h[i]>k-1) {
                ans=false;
                break;
            }
        }
        hightmax=h[n-1];
        hightmin=h[n-1];
        for(ll i=n-2;i>=0;i--) {
            hightmax+=k-1;
            hightmin-=k-1;
            if(hightmin<h[i]) {
                hightmin=h[i];
            }
            if(hightmax<h[i]) {
                ans=false;
                break;
            }
            if(hightmin-h[i]>k-1) {
                ans=false;
                break;
            }
        }
        ans?cout<<"YES"<<endl:cout<<"NO"<<endl;
    }
}