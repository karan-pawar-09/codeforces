/*
author:Karan
created:09.08.2021 20:25:19
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

ll binarysearch(vector<ll> &ar,ll a) {
    ll l=0;
    ll r=ar.size();
    while(l+1<r) {
        ll m=l+(r-l)/2;
        if(ar[m]<=a) {
            l=m;
        }
        else {
            r=m;
        }
    }
    return l;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        ll n,k;
        cin>>n>>k;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++) {
            cin>>arr[i];
        }
        vector<ll> ar(n);
        ar=arr;
        sort(all(ar));
        ll no=n;
        for(ll i=1;i<n;i++) {
            ll indx=binarysearch(ar,arr[i]);
            if(indx>0)
                if(ar[indx-1]==arr[i-1]) {
                    no--;
                }
        }       
        if(no<=k) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
     
    } 
}

