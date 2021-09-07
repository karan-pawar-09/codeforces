/*
author:Karan
created:26.07.2021 16:20:21
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
    int a,b;
    cin>>a>>b;
    double c=((double)(a-b)/3)+(double) b;
    cout<<setprecision(10);
    cout<<fixed;
    cout<<c<<endl;
}