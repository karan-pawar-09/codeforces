/*
author:Karan
created:26.06.2021 17:34:28
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
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    {
        ll l=-1;
        ll r=(ll)1e8+7;
        while(l+1<r) {
            ll m=l+(r-l)/2;
            if(a+b*m<=d*c*m) {
                r=m;
            }
            else {
                l=m;
            }
        }
        if(r==(ll)1e8+7) cout<<-1<<endl;
        else cout<<r<<endl;
    }
}