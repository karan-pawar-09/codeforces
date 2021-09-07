/*
author:Karan
created:03.07.2021 11:14:20
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    vector<ll> freq(107,0);
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        freq[arr[i]]++;
    }
    ll one=0;
    ll two=0;
    for(ll i=0;i<107;i++) {
        if(freq[i]<1) {
            one=i;
            break;
        }
    }
    for(ll i=0;i<107;i++) {
        if(freq[i]<2) {
            two=i;
            break;
        }
    }
    cout<<one+two<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        solve();
    }
}