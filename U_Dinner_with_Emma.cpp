#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> arr(n,vector<ll>(m,0));
    for(ll i=0;i<n;i++) {
        for(ll j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }   
    ll row=0;
    ll price=0;
    for(ll i=0;i<n;i++) {
        sort(arr[i].begin(),arr[i].end());
    }
    sort(arr.begin(),arr.end());
    cout<<arr[n-1][0]<<endl;
}