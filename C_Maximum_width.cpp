/*
author:Karan
created:28.05.2021 13:40:16
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    string s,t;
    cin>>n>>m;
    cin>>s>>t;
    vector<pair<char,ll>> arr(n);
    for(ll i=0;i<n;i++) {
        arr[i]={s[i],i};
    }
    vector<ll> mini(m,(ll)INT_MAX);
    vector<ll> maxi(m,0);
    int ptr=0;
    for(int i=0;i<m;i++) {
        for(int j=ptr;j<n;j++) {
            if(s[j]==t[i]) {
                mini[i]=j;
                ptr=j+1;
                break;
            }
        }
    }
    ptr=n-1;
    for(int i=m-1;i>=0;i--) {
        for(int j=ptr;j>=0;j--) {
            if(s[j]==t[i]) {
                maxi[i]=j;
                ptr=j-1;
                break;
            }
        }
    }
    ll ans=1;
    for(ll i=1;i<m;i++) {
        ans=max(ans,(ll)maxi[i]-(ll)mini[i-1]);
    }
    cout<<ans<<endl;
}