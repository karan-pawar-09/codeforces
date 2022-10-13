/*
    author:Karan
    created:03.08.2022 20:55:12
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

set<pair<ll,ll>> printDivisors(ll n) {
    set<pair<ll,ll>> s;
    ll a,b;
    for (ll i=1; i*i <= n; i++) {
        if (n%i == 0) {
            if (n/i == i) {
                s.insert({i,i});
            } else {
                a=i;
                b = n/i;
                if(a>b) {
                    swap(a,b);
                }
                s.insert({a,b});
            }
        }
    }
    return s;
}

void solve() {
    ll xx,yy;
    cin>>xx>>yy;
    set<pair<ll,ll>> s = printDivisors(yy);
    for(auto x: s) {
        ll a = x.first;
        ll b = x.second;
        assert(a<=b);
        ll k = min(xx, a-1);
        if((k*2)>=xx) {
            ll c = k;
            ll d = xx-k;
            if(c>d) {
                swap(c,d);
            }
            cout<<a<<" "<<b<<endl;
            cout<<c<<" "<<d<<endl;
            return;
        }
    }
    for(auto x: s) {
        ll a = x.first;
        ll b = x.second;
        assert(a<=b);
        ll k = b+1;
        if((k*2)<=xx) {
            ll c = k;
            ll d = xx-k;
            if(c>d) {
                swap(c,d);
            }
            cout<<a<<" "<<b<<endl;
            cout<<c<<" "<<d<<endl;
            return;
        }
    }
    cout<<-1<<endl;
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