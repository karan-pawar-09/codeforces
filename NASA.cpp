/*
    author:Karan
    created:09.06.2023 21:11:03
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

const ll mx = (1 << 15) +10;
set<ll> pal;

bool isPd(string &s) {
    ll n = s.size();
    for(ll i = 0; i < n/2; i++) {
        if(s[i] != s[n-1-i]) return false;
    }
    return true;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    vector<ll> used(mx, 0);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ll ans = 0;
    for(ll i = 0; i < n; i++) {
        used[arr[i]] ++;
        for(auto x: pal) {
            if((arr[i] ^ x) < mx)
                ans += used[arr[i] ^ x];
        }
    }

    cout<<ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    for(ll i = 0 ; i <= mx; i++) {
        string temp = to_string(i);
        if(isPd(temp)) {
            pal.insert(i);
        }
    }
    ll t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}