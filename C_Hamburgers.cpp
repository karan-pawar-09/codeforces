/*
    author:Karan
    created:20.02.2023 20:45:07
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

ll binarysearch(vector<ll> &req, vector<ll> &quantity, vector<ll> &price, ll money) {
    ll l = 0;
    ll r = 1e15+10;
    while(l+1 < r) {
        ll m = l+(r-l)/2;
        ll moneyReq =  0;
        for(ll i=0;i<3;i++) {
            if(quantity[i] < m*req[i]) {
                moneyReq += (m*req[i] -quantity[i]) * price[i];
            }
        }
        if(moneyReq <= money) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}
void solve() {
    string s;
    cin>>s;
    vector<ll> quantity(3), price(3);
    vector<ll> req(3, 0);
    for(auto x: s) {
        if(x=='B') {
            req[0]++;
        } else if(x == 'S') {
            req[1]++;
        } else {
            req[2]++;
        }
    }
    for(ll i=0;i<3;i++) {
        cin>>quantity[i];
    }
    for(ll i=0;i<3;i++) {
        cin>>price[i];
    }
    ll money;
    cin>>money;
    cout<<binarysearch(req, quantity, price, money)<<endl;
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