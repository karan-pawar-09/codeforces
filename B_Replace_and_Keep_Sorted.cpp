#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q,k;
    cin>>n>>q>>k;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    
    vector<ll> ar(n,0);
    for(ll i=1;i<n-1;i++) {
        ar[i]=arr[i+1]-arr[i-1]-2;
    }
    vector<ll> ans(n+1,0);
    for(ll i=0;i<n;i++) {
        ans[i+1]=ans[i]+ar[i];
    }

    for(ll i=0;i<q;i++) {
        ll l,r;
        cin>>l>>r;
        if (r - l == 0) {
            cout << k - 1 << endl;
            continue;
        }
        ll prefsum=ans[r-1]-ans[l];
        ll start=max(arr[l]-2,0LL);
        ll end=max(k-1-arr[r-2],0LL);
        cout<<prefsum+start+end<<endl;
    }
    
}