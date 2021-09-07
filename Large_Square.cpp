/*
author:Karan
created:17.08.2021 20:06:59
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

ll size;
ll n;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        ll a;
        cin>>n>>a;
        ll temp=1;
        ll len=0;
        size=0;
        while(size*size<=n) {
            size++;
        }
        size--;
        cout<<max(size*a,a)<<endl;
    }
}