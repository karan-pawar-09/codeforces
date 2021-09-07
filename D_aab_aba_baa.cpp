/*
author:Karan
created:24.05.2021 09:39:22
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,k;
    cin>>a>>b>>k;
    ll n=a+b;
    vector<vector<ll>> ncr(61,vector<ll> (61));
    ncr[0][0]=1;
    for(int i=1;i<=60;i++) {
        ncr[i][0]=1;
        for(int j=1;j<i;j++) {
            ncr[i][j]=ncr[i-1][j]+ncr[i-1][j-1];
        }
        ncr[i][i]=1;
    }
    for(int i=0;i<n;i++) {
        ll count=ncr[a-1+b][a-1];
        if(count>=k&&a>0) {
            cout<<"a";
            a--;
        }
        else {
            cout<<'b';
            b--;
            k-=count;
        }
    }
}