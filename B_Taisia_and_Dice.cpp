/*
    author:Karan
    created:27.01.2023 20:20:34
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
    ll n, s2, s1;
    cin>>n>>s2>>s1;
    ll one = s2-s1;
    ll sum = one;
    multiset<ll,greater<ll>> s;
    
    s.insert(one);
    while(sum < s2) {
        ll k = min(one, s2-sum);
        sum += k;
        s.insert(k);
    }
    s.erase(s.find(one));
    while(s.size() < (n-1)) {
        ll top = *s.begin();
        s.erase(s.begin());
        
        ll one1 = top/2;
        ll two2 = top - one1;
        
        s.insert(one1);
        s.insert(two2);
        
    }
    s.insert(one);
    int totall = 0;
    for(auto x: s) {
        totall += x;
        cout<<x<<" ";
    }
    assert(totall==s2);
    assert(n==s.size());
    assert(s.count(one));
    cout<<endl;
    //while(s.size() <)
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