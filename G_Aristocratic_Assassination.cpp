/*
    author:Karan
    created:04.01.2022 23:49:37
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

struct item {
    ll seg,pref,suf,sum;
};

struct segtree {
    ll size;
    vector<item> items;
    item NEUTRAL_ELEMENT={0,0,0,0};
    item merge(item a,item b) {
        return {max({a.seg,b.seg,a.suf+b.pref}),max(a.pref,a.sum+b.pref),max(b.suf,b.sum+a.suf),a.sum+b.sum};
    }
    item single(ll v) {
        return {v,v,v,v};       
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

void solve() {
    ll n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    ll g=0;
    vector<ll> ar;
    for(auto x:s) {
        if(x=='G') {
            g++;
            ar.push_back(-1);
        } else {
            ar.push_back(1);
        }
    }
    segtree st;
    st.init(n);
    st.build(ar);
    while(q--) {
        ll a,b;
        cin>>a>>b;
        a--;
        item res=st.calc(a,b);
        ll inv=res.seg;
        cout<<g+max(0LL,inv)<<endl;
    }
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