/*
author:Karan
created:05.06.2021 19:01:51
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    long double N;
    cin>>N;
    ll n=ceil(N);   
    ll ff=0; 
    if(n>(int)1e5) {
        ll diff=n-(ll)1e5;
        ff=diff/4;
        n-=ff*4;
    }
    vector<ll> dp(n+1,(ll)1e18+7);
    dp[0]=0;
    vector<ll> arr(3);
    vector<ll> one(n+1,0);
    vector<ll> three(n+1,0);
    vector<ll> four(n+1,0);
    arr[0]=1;
    arr[1]=3;
    arr[2]=4;
    for(ll i=0;i<3;i++) {
        for(ll j=1;j<=n;j++) {
            if(j>=arr[i]) {
                {
                    if(dp[j-arr[i]]+1<=dp[j]) {
                        dp[j]=dp[j-arr[i]]+1;
                        if(i==0) {
                            one[j]=one[j-arr[i]]+1;
                        }
                        else if (i==1) {
                            one[j]=one[j-arr[i]];
                            three[j]=three[j-arr[i]]+1;
                        }
                        else {
                            one[j]=one[j-arr[i]];
                            three[j]=three[j-arr[i]];
                            four[j]=four[j-arr[i]]+1;
                        }
                    }
                }
            }
        }
    }
    cout<<one[n]<<endl<<three[n]<<endl<<four[n]+ff<<endl;
}