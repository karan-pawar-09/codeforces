/*
author:Karan
created:24.07.2021 14:17:49
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
    int t;
    cin>>t;
    while(t--) {
        long double a,b;
        cin>>a>>b;
        cout<<setprecision(10);
        cout<<fixed;
        cout<<max((long double)0,6-a-b)/6<<endl;
    }
}