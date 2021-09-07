/*
author:Karan
created:21.08.2021 17:32:40
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
    ll n;
    cin>>n;
    ll k=0;
    ll pow=1;
    while((pow*2) <= n) {      
        k++;
        pow*=2;
    }
    cout<<k<<endl;
}