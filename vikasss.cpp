
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()

const ll inf = 1e18+10;

void solve() {
    ll n;
    cin >> n;
    vector<vector<ll>> arr(n);
    for(ll i=0;i<n;i++) {
        ll temp;
        cin>>temp;
        ll maxi = -inf;
        for(ll j=0;j<temp;j++) {
            ll temp1;
            cin>>temp1;
            arr[i].push_back(temp1);
            maxi = max(maxi, temp1-j);
        }
        arr[i].push_back(maxi);
    }
    sort(all(arr), [&](vector<ll> a, vector<ll> b) {
        return a.back() < b.back();
    });
    ll prev = 0;
    ll res = -inf;
    for(ll i=0;i<n;i++) {
        res = max(res, arr[i].back() - prev);
        prev += arr[i].size()-1;
    }
    cout<<res+1<<endl;
}

int32_t main() {

    ll t=1;
    while(t--) {
        solve();
    }
}