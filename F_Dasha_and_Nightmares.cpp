/*
    author:Karan
    created:03.03.2023 15:59:53
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


ll calc(char c, ll n, vector<string> &arr) {
    map<ll, ll> ODD;
    for(ll i = 0; i < n;i++) {
        int num = 0;
        for(auto y: arr[i]) {
            num ^= (1 << (y-'a'));
        }   
        if((num & (1 << (c-'a'))) == 0) {
            ODD[num]++;
        }
    }
    ll ans = 0;
    for(ll i = 0; i< n;i++) {
        int temp = 0;
        int isThere = 0;
        for(int i=0;i<26;i++) {
            if(i != (c-'a'))
                temp |= (1<<i);
        }
        for(auto y: arr[i]) {
            temp ^= (1 << (y-'a'));
            isThere |= (1 << (y-'a'));
        }
        if((isThere & (1<<(c-'a'))) == 0) {
            ans += ODD[temp];
        }
    }
    return ans;
}

void solve() {
    ll n;
    cin >> n;
    vector<string> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    ll res = 0;
    for(char c = 'a'; c <= 'z'; c++) {
        res += calc(c, n, arr);
    }
    cout<<res/2<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}