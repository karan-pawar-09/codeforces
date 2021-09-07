/*
author:Karan
created:26.06.2021 14:57:47
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
    int m,n;
    cin>>m>>n;
    long double ans=0;
    for(int i=1;i<=m;i++) {
        ans+=(pow(((long double)i/m),n)-pow((long double)(i-1)/m,n))*i;
    }
    cout<<fixed;
    cout<<setprecision(12);
    cout<<ans<<endl;
}