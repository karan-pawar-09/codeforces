/*
author:Karan
created:06.06.2021 17:42:04
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
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }   
    ll ans=0;
    for(ll i=0;i<n;i++) {
        if(arr[i]<=10) {

        }
        else {
            ans+=arr[i]-10;
        }
    }
    cout<<ans<<endl;
}