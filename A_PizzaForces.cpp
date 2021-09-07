/*
author:Karan
created:30.07.2021 20:05:27
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
        if(n<6) {
            cout<<15<<endl;
        }
        else {
            n%2?n++:n;
            cout<<(n/2)*5<<endl;
        }
    
    }
}