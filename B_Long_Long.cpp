/*
    author:Karan
    created:20.06.2023 20:08:39
*/
#if true
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
#define mset(a,x) memset(a,x,sizeof(a))
#endif

bool similar(ll a, ll b) {
    if(a == 0 || b == 0) return true;
    if(a <= 0) {
        if(b <= 0) return true;
        else return false;
    } else {
        if(b >= 0) return true;
        else return false;
    }
}
void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    ll res = 0;
    for(ll i = 0; i < n; i++) {
        cin>>arr[i];
        res += abs(arr[i]);
    }
    vector<ll> ar;
    for(ll i = 0; i < n; i++) {
        if(i == 0) {
            ar.push_back(arr[i]);
        } else {
            if(similar(ar.back(), arr[i])) {
                ar.back() = min(ar.back(), arr[i]);
            } else {
                ar.push_back(arr[i]);
            }
        }
    }
    ll count = 0;
    for(auto x: ar) {
        if(x < 0) count++;
    }
    cout<<res<<" "<<count<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}