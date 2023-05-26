
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin>>n;
    vector<char> arr(n);
    char c;
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    cin>>c;
    ll total = 0;
    ll count = 0;
    ll prev = 0;
    for(ll i=0;i<n;i++) {
        if(arr[i] == c) {
            total += i;
            count++;
        }
    }
    ll res = 0;
    ll ans = 1e18+10;
    for(ll i=0;i<n;i++) {
        if(arr[i] == c) {
            prev++;
            res += i;
            ll k1 = ((prev-1)*(prev)) / 2;
            ll k2 = ((count-1) * count) /2;
            ans = min(ans, (prev*i)-res - k1 + total - (count*i) - k2);
            count--;
            total -= i;
        }
    }
    cout<<ans<<endl;
}

int32_t main() {
    ll t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}