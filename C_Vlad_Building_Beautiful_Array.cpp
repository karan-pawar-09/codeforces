/*
    author:Karan
    created:19.06.2023 20:57:13
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

const ll inf = 1e18+10;

bool one(ll n, vector<ll> &arr) {
    ll miniodd = inf;
    for(auto x: arr) {
        if(x%2)
            return false;
    }
   return true;
}

bool two(ll n, vector<ll> &arr) {
    ll miniodd = inf;
    for(auto x: arr) {
        if(x%2) {
            miniodd = min(miniodd, x);
        }
    }
    //cout<<miniodd<<endl;
    for(auto x: arr) {
        if(x % 2 == 0) {
            if(miniodd > x) return false;
        }
    }
    return true;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n;i++) {
        cin>>arr[i];
    }
    (one(n, arr) || two(n, arr))?cout<<"YES"<<endl:cout<<"NO"<<endl;
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