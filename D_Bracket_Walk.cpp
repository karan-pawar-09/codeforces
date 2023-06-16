/*
    author:Karan
    created:05.06.2023 23:14:20
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
    ll n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    set<ll> st;
    for(ll i = 0; i < n; i++) {
        if(i%2 && s[i]=='(') st.insert(i);
        if(i%2 == 0 && s[i] == ')') st.insert(i);
    }
    while(q--) {
        ll k;
        cin >> k;
        k--;
        if(st.count(k)) st.erase(k);
        else st.insert(k);
        if(n%2) {
            cout<<"NO"<<endl;
            continue;
        }
        if(st.size() && (*st.begin()%2 == 0 || *st.rbegin()%2)) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
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