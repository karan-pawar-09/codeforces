/*
author:Karan
created:16.07.2021 15:01:03
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

bool isGood(ll m,ll sum) {
    if(((m*(2+(m-1)*2))/2)>=sum) return true;
    return false;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        ll sum;
        cin>>sum;
        ll l=0;
        ll r=1e9+7;
        while(l+1<r) {
            ll m=l+(r-l)/2;
            if(isGood(m,sum)) {
                r=m;
            }
            else {
                l=m;
            }
        }
        cout<<r<<endl;
    }
    
}