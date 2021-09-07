/*
author:Karan
created:20.06.2021 21:30:23
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

ll binarysearch(ll a,vector<ll> &arr) {
    ll l=0;
    ll r=arr.size();
    while(l+1<r) {
        ll m=l+(r-l)/2;
        if(a>=arr[m]) {
            l=m;
        }
        else {
            r=m;
        }
    }
    return l;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll n,q;
    ll a;
    cin>>n>>q;
    vector<ll> arr(n+1);
    arr[0]=(ll)-1e18+7;
    for(ll i=1;i<=n;i++) {
        cin>>arr[i];
    } 
    sort(all(arr));
    while(q--) {        
        cin>>a;
        ll k=binarysearch(a,arr);
        if(arr[k]==a) {
            cout<<0<<endl;
        }
        else {
            if(k%2) {
                cout<<"NEGATIVE"<<endl;
            }
            else {
                cout<<"POSITIVE"<<endl;
            }
        }
    } 
}