/*
    author:Karan
    created:07.09.2021 17:51:23
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    long double x;
    cin>>x;
    ll k=x*10;
    if(k%10 <=2) {
        cout<<k/10<<"-"<<endl;
    }
    else if(k%10<=6) {
        cout<<k/10<<endl;
    }
    else cout<<k/10<<"+"<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}