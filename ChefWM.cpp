/*
    author:Karan
    created:05.01.2022 22:13:08
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

set<ll> s;
set<ll> s1;

void primeFactors(ll n) { 
    while (n % 2 == 0) { 
        s.insert(2);
        n = n/2; 
    } 
    for (ll i = 3; i*i <= n; i = i + 2) { 
        while (n % i == 0) { 
            s.insert(i);
            n = n/i; 
        } 
    } 
    if (n > 2) 
        s.insert(n);
} 
void primeFactors1(ll n) { 
    for(ll i=1;i*i<=n;i++) {
        if(n%i==0) {
            s1.insert(i);
            if(n%(n/i)==0) {
                s1.insert(n/i);
            }
        } 
    }
}

void solve() {
    ll n,m;
    cin>>n>>m;
    s.clear();
    s1.clear();
    primeFactors(m);
    primeFactors1(n);
    vector<ll> ar;
    ar.push_back(0);
    for(auto x:s1) {
        ar.push_back(x);
    }
    ll i=0;
    for(i=0;i<ar.size();i++) {
        if(ar[i]>s.size()) {
            break;
        }
    }
    i--;
    cout<<ar[i]<<endl;
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