/*
author:Karan
created:18.08.2021 20:20:38
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
        ll k;
        cin>>k;
        if(k==1) cout<<1<<" "<<1<<endl;
        else {
            ll q;
            ll l=1;
            ll r=1e9+7;
            while(l+1<r) {
                ll m=l+(r-l)/2;
                if((m*m)<k) {
                    l=m;
                }
                else {
                    r=m;
                }
            }
            q=l;
            k-=(q*q);
            ll row=min(k,q+1);
            k-=q+1;
            ll col=q+1;
            if(k>0) {
                col-=k;
            }
            cout<<row<<" "<<col<<endl;
        }
    }
}