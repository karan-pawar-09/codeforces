/*
author:Karan
created:30.05.2021 13:36:49
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
const ll mini=(ll)-1e10;
const int N=5e3+7;
ll dp[N][N];
ll arr[N];
ll ans(int i,int j) {
    if(i>j) {
        return 0;
    }
    if(dp[i][j]!=mini) {
        return dp[i][j];
    }
    ll res=max(min((arr[i]+ans(i+2,j)),(arr[i]+ans(i+1,j-1))),min((arr[j]+ans(i+1,j-1)),(arr[j]+ans(i,j-2))));
    dp[i][j]=res;
    return dp[i][j];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            dp[i][j]=mini;
        }
    }
    ll score=ans(0,n-1);
    cout<<score<<endl;
}