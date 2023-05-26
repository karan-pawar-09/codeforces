/*
    author:Karan
    created:01.02.2023 22:02:37
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

void rec(ll no, ll i, ll k, ll n) {
    if(i == n) {
        if(__builtin_popcount(no) <= k) {
            s.insert(no);
        }
        return;
    }
    ll pp = i;
    rec(no, i+1, k, n);
    no |= (1<<pp);
    rec(no, i+1, k, n);
}

void solve() {
    ll n, k;
    cin >> n >> k;
    s.clear();
    set<char> st;
    string a, b;
    cin>>a;
    cin>>b;
    for(auto x: a) {
        st.insert(x);
    }
    vector<ll> arr(all(st));
    ll temp = st.size();
    rec(0, 0, k, temp);
    ll maxi = 0;
    for(auto x: s) {
        set<char> temp;
        for(ll i=0;i<arr.size();i++) {
            if(x&(1<<i)) {
                temp.insert(arr[i]);
            }
        }
        string tt = a;
        ll ct = 0;
        ll res = 0;
        for(ll i = 0;i<n;i++) {
            if(a[i] == b[i] || temp.count(a[i])) {
                ct++;
            } else {
                res += (ct * (ct+1))/2;
                ct = 0;
            }
        }
        res += (ct * (ct+1))/2;
        maxi = max(maxi, res);
    }
    cout<<maxi<<endl;
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