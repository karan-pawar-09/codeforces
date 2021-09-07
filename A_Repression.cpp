/*
author:Karan
created:26.06.2021 17:30:22
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
    int a,b,c;
    cin>>a>>b>>c;
    cout<<max({a+b,a+c,b+c})<<endl;
}