/*
    author:Karan
    created:07.09.2021 13:32:47
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

struct item {
    ll ans,pref,suf,len,first,last;
};

struct segtree {
    ll size;
    item ret;
    vector<item> items;
    item NEUTRAL_ELEMENT={0,0,0,0,0,0};
    item merge(item a,item b) {        
        ret.ans=a.ans+b.ans;
        ret.pref=a.pref;
        ret.suf=b.suf;
        ret.len=a.len+b.len;
        ret.first=a.first;
        ret.last=b.last; 
        if(a.last<=b.first) {
            ret.ans+=a.suf*b.pref;
        }
        if(a.pref==a.len and a.last<=b.first) {
            ret.pref+=b.pref;
        }
        if(b.suf == b.len and a.last<=b.first) {
            ret.suf=a.suf+b.len;
        }
        return ret;
    }
    item single(ll v) {
        return {1,1,1,1,v,v};       
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
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    segtree st;
    st.init(n);
    st.build(arr);
    ll a,b,c;
    while(q--) {
        cin>>a>>b>>c;
        if(a==1) {
            st.set(b-1,c);
        }
        else {
            cout<<st.calc(b-1,c).ans<<endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}