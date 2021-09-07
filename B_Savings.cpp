/*
author:Karan
created:19.06.2021 17:34:38
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
    ll n;
    cin>>n;
    ll l=0;
    ll r=1e9+7;
    while(l+1<r) {
        ll m=l+(r-l)/2;
        if(((m*(m+1))/2)>=n) {
            r=m;
        }
        else {
            l=m;
        }
    }
    cout<<r<<endl;
}