#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<pair<ll,ll>> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i].first>>arr[i].second;
    }
    int q;
    cin>>q;
    while(q--) {
        ll k;
        cin>>k;
        ll ans=0;
        for(int i=0;i<n;i++) {
            if(arr[i].second==1) {
                k=k+arr[i].first;
            }
            else if(arr[i].second==2) {
                k=max(k,arr[i].first);
            }
            else {
                k=min(k,arr[i].first);
            }
        }
        cout<<k<<endl;
    }
}