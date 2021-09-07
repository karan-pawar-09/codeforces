/*
author:Karan
created:23.07.2021 20:05:20
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
        ll n;
        cin>>n;
        if(n%3==0) {
            cout<<n/3<<" "<<n/3<<endl;
        }
        else if(n%3==1) {
            cout<<(n/3)+1<<" "<<n/3<<endl;
        }
        else {
            cout<<n/3<<" "<<(n/3)+1<<endl;
        }
    }
}