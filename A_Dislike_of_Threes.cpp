/*
author:Karan
created:18.08.2021 20:05:42
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
        ll p=0;
        ll i=1;
        for(i;i<1e6 and (p<k);i++) {
            if(i%3==0) continue;
            else if((i%10)==3) continue;           
            else p++;
        }
        cout<<i-1<<endl;
    }
}