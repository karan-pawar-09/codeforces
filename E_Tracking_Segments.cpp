/*
    author:Karan
    created:20.06.2023 20:46:16
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

#define item long long

struct segtree {
    ll size;
    vector<item> items;
    item NEUTRAL_ELEMENT = 0LL;
    item merge(item a,item b) {
        return a + b;
    }
    item single(ll v) {
        return v;       
    }
    void init(ll n) {
        size=1;
        while(size<n) {
            size*=2;
        }
        items.resize(2*size);
    }
    void build(vector<ll> &a,ll x,ll lx,ll rx) {
        if(rx-lx==1) {
            if(lx<((ll)a.size())) {
                items[x]=single(a[lx]);
            }
            return;
        }
        ll m=lx+(rx-lx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        items[x]=merge(items[2*x+1],items[2*x+2]);
    }
    void build(vector<ll> &a) {
        build(a,0,0,size);
    }
    void set(ll i,ll v,ll x,ll lx,ll rx) {
        if(rx-lx==1) {
            items[x]=single(v);
            return;
        }
        ll m=lx+(rx-lx)/2;
        if(i<m) {
            set(i,v,2*x+1,lx,m);
        }
        else {
            set(i,v,2*x+2,m,rx);
        }
        items[x]=merge(items[2*x+1],items[2*x+2]);
    }
    void set(ll i,ll v) {
        set(i,v,0,0,size);
    }
    item calc(ll l,ll r,ll x,ll lx,ll rx) {
        if(lx>=r|l>=rx) return NEUTRAL_ELEMENT;
        if(lx>=l&&rx<=r) return items[x];
        ll m=lx+(rx-lx)/2;
        item s1=calc(l,r,2*x+1,lx,m);
        item s2=calc(l,r,2*x+2,m,rx);
        return merge(s1,s2);
    }
    item calc(ll l,ll r) {
        return calc(l,r,0,0,size);
    }
};

bool isGood(ll m , vector<pair<ll, ll>> & arr, vector<ll> & qr, ll n, segtree &st) {
    for(ll i = 0; i < n; i++) st.set(i, 0);
    for(ll i = 0; i < m; i++) {
        st.set(qr[i], 1);
    }
    for(auto x: arr) {
        ll sum = st.calc(x.first, x.second + 1);
        if((sum * 2LL) > (x.second - x.first + 1)) return true;
    }
    return false;
}

ll binraysearch(vector<pair<ll, ll>> & arr, vector<ll> & qr, ll n, segtree &st) {
    ll l = -1;
    ll r = qr.size();
    while(l + 1 < r) {
        ll m = l + (r - l) / 2;
        if(isGood(m, arr, qr, n, st)) {
            r = m;
        } else {
            l = m;
        }
    }
    if(isGood(r, arr, qr, n, st)) return r;
    else return -1;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> ar(n, 0);
    vector<pair<ll, ll>> arr(m);
    for(ll i = 0; i < m; i++) {
        cin >> arr[i].first >> arr[i].second;
        arr[i].first--;
        arr[i].second--;
    }
    ll q;
    cin >> q;
    vector<ll> qr(q);
    for(ll i = 0; i < q; i++) {
        cin >> qr[i];
        qr[i]--;
    }
    segtree st;
    st.init(n+10);
    st.build(ar);
    cout<<binraysearch(arr, qr, n, st)<<endl;
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