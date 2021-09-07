/*
author:Karan
created:30.06.2021 12:35:30
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
    int n,m;
    cin>>n>>m;
    n=min(n,m);
    cout<<n+1<<endl;
    for(int i=0;i<=n;i++) {
        cout<<i<<" "<<n-i<<endl;
    }
}