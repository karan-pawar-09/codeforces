/*
    author:Karan
    created:08.02.2023 20:33:37
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

void solve() {
    ll n;
    cin>>n;
    vector<ll> arr(n);
    map<ll, ll> M;
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        M[arr[i]]++;
    }
    vector<pair<ll, ll>> ar;
    for(auto x : M) {
        ar.push_back({x.first, x.second});
    }
    sort(all(ar), greater<pair<ll, ll>>());

    bool special = false;
    for(auto x: ar) {
        if(x.second % 2) {
            special = true;
        }
    }
    if(special) {
        cout<<"Marichka"<<endl;
    } else {
        cout<<"Zenyk"<<endl;
    }
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