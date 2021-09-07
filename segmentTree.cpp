#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
struct item {
    ll seg,pref,suf,sum;
};
struct segtree {
    ll size;
    vector<item> items;
    item NEUTRAL_ELEMENT={0LL,0LL,0LL,0LL};
    item merge(item a,item b) {
        return {
            max({a.seg,b.seg,(a.suf+b.pref)}),
            max(a.pref,a.sum+b.pref),
            max(b.suf,b.sum+a.suf),
            a.sum+b.sum
        };
    }
    item single(ll v) {
        if(v>0LL) {
            return {v,v,v,v}
        }
        else {
            return {0LL,0LL,0LL,v};
        }        
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
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    segtree st;
    st.init(n);
    vector<ll> a(n);
    for(ll i=0;i<n;i++) {
        cin>>a[i];
    }
    st.build(a);
    while(m--) {
        ll op;
        cin>>op;
        if(op==1) {
            ll i,v;
            cin>>i>>v;
            st.set(i,v);
        }
        else {
            ll l,r;
            cin>>l>>r;
            item k=st.calc(l,r);
            cout<<k.m<<" "<<k.c<<endl;
        }
    }
}