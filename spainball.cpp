#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<ll> arr(m);
    for(ll i=0;i<m;i++) {
        cin>>arr[i];
    }
    sort(all(arr));
    ll mini=(ll)1e18;
    for(ll i=1;i<m;i++) {        
        mini=min(mini,(arr[i]-arr[i-1]-1));        
    }
    if(m==0) {
        cout<<"1"<<endl;
    }
    else {
        if(arr[0]!=1) {
            mini=min(mini,arr[0]-0-1);
        }
        if(arr[n-1]!=n) {
            mini=min(mini,n+1-arr[n-1]-1);
        }
        ll ans=0;
        for(int i=1;i<m;i++) {
            ans+=ceil((double)(arr[i]-arr[i-1]-1)/mini);
        }

        ans+=ceil((double)(arr[0]-0-1)/mini);
        ll kk=n-arr[m-1];
        ans+=ceil((double)kk/mini);
        cout<<ans<<endl;
    }
}