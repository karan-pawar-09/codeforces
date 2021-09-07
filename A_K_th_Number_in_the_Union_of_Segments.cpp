#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

ll calc(int x,vector<pair<ll,ll>>arr,int n) {
    ll sum=0;
    for(int i=0;i<n;i++) {
        if(arr[i].first<=x) {
            sum+=min(x-arr[i].first,arr[i].second-arr[i].first+1);
        }
    }
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    vector<pair<ll,ll>>arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i].first>>arr[i].second;
    }
    ll l=-(((ll)1e9)*2+8);
    ll r=((ll)1e9)*2+8;
    while(r>l+1) {
        ll m=l+(r-l)/2;
        if(calc(m,arr,n)<=k) {
            l=m;
        } 
        else {
            r=m;
        }
    }
    cout<<l<<endl;
}