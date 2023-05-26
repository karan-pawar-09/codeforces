/*
    author:Karan
    created:19.02.2023 17:38:43
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
    string s;
    cin>>s;
    ll no = 0;
    for(auto x: s) {
        if(x == '+') {
            no++;
        } else {
            no--;
        }
    }
    ll q;
    cin>>q;
    while(q--) {
        ll a, b;
        cin>>a>>b;
        if(a==b) {
            if(no==0) {
                cout<<"YES"<<endl;
            } else {
                cout<<"NO"<<endl;
            }
        } else {
            ll k1 = (no*a) % (a-b);
            ll k2 = (no*a) / (a-b);
            ll k3 = (no*b) % (b-a);
            ll k4 = (no*b) / (b-a);
            ll k5 = no-k2;
            ll k6 = no-k4;
            if(k1==0 && (abs(k2)+abs(k5) <= n)  || ((k3==0) &&(abs(k4)+abs(k6) <= n))) {
                cout<<"YES"<<endl;
            } else {
                cout<<"NO"<<endl;
            }
        }
    }
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