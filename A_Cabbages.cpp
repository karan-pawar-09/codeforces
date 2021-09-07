/*
author:Karan
created:17.07.2021 17:30:57
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
    int n,x,y,a;
    cin>>n>>a>>x>>y;
    if(a<=n) {
        cout<<a*x+(n-a)*y<<endl;
    }
    else {
        cout<<n*x<<endl;
    }
}