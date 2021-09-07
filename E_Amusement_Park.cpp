/*
    author:Karan
    created:07.09.2021 18:46:10
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

ll sum(ll a,ll b) {
    return ((a*(a+1))/2)-((b*(b+1))/2);
}
void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll> arr(n+1,0);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    sort(all(arr),greater<ll>());
    ll ans=0;
    for(ll i=0;i<n and k>0;i++) {
        ll nos=(arr[i]-arr[i+1])*(i+1);
        if(nos<=k) {
            k-=nos;
            ans+=(i+1)*(sum(arr[i],arr[i+1]));
        }
        else {
            ll full=k/(i+1);
            ans+=(i+1)*(sum(arr[i],arr[i]-full));
            ans+=(k%(i+1))*(arr[i]-full);
            k=0;
            break;
        }
    }
    
    cout<<ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}