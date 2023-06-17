/*
author:Karan
created:05.09.2021 13:37:41
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const ll mod=(ll)1e9+7;


#define item long long
// struct item {
//     ll seg,pref,suf,sum;
// };
struct segtree {
    ll size;
    vector<item> items;
    item NEUTRAL_ELEMENT=(ll)0;
    item merge(item a,item b) {
        return a+b;
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
    ll solve(ll k,ll lx, ll rx,ll root) {
        if(rx-lx==1) {
            return lx;
        }
        ll m=lx+(rx-lx)/2;
        if(k<items[2*root+1]) {
            return solve(k,lx,m,2*root+1);
        }
        else {
            return solve(k-items[2*root+1],m,rx,2*root+2);
        }
    }
    ll solve(ll k) {
        return solve(k,0,size,0);
    }
};
void solve() {
    ll n,m;
    cin>>n>>m;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    segtree st;
    st.init(n);
    st.build(arr);
    ll a,b;
    while(m--) {
        cin>>a>>b;
        if(a==1) {
            arr[b]=1-arr[b];
            st.set(b,arr[b]);
        }
        else {
            cout<<st.solve(b)<<endl;
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