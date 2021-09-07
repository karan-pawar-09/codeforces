/*
author:Karan
created:04.06.2021 18:02:02
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
    ll mx=(ll)1e18+7;
    ll t;
    cin>>t;
    while(t--) {
        ll n,m;
        cin>>n>>m;
        vector<ll> a(n);
        for(ll i=0;i<n;i++) {
            cin>>a[i];
        }
        vector<ll> ans(n,mx);
        ll p=mx;
        for(ll i=0;i<n;i++) {
            if(a[i]==1) {
                p=0;
                ans[i]=min(ans[i],p);
                
            }
            else {
                ans[i]=min(ans[i],p);
            }
            p++;
        }
        p=mx;
        for(ll i=n-1;i>=0;i--) {
            if(a[i]==2) {
                p=0;
                ans[i]=min(ans[i],p);                
            }
            else {
                ans[i]=min(ans[i],p);
            }
            p++;
        }
        ans[0]=0LL;
        while(m--) {
            ll k;
            cin>>k;
            k--;
            if(ans[k]==mx) {
                cout<<"-1 ";
            }
            else {
                cout<<ans[k]<<" ";
            }
        }
        cout<<endl;
    }
}