/*
author:Karan
created:11.07.2021 14:08:18
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

#define item long long
// struct item {
//     ll seg,pref,suf,sum;
// };
struct segtree {
    ll size;
    vector<item> items;
    item NEUTRAL_ELEMENT=(ll)0;
    item merge(item a,item b) {
        return __gcd(a,b);
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


bool isGood(vector<ll> &ar) {
    ll n=ar.size();
    bool ans=true;
    for(ll i=1;i<n;i++) {
        if(ar[i]!=ar[i-1]) {
            ans=false;
            break;
        }
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        vector<ll> ar(n);
        vector<ll> arr(2*n);
        for(ll i=0;i<n;i++) {
            cin>>arr[i];
        }
        for(ll i=n;i<2*n;i++) {
            arr[i]=arr[i-n];
        }
        struct segtree st;
        st.init(2*n);
        st.build(arr);
        
        ll l=0;
        ll r=n+1;
        while(l+1<r) {
            ll m=l+(r-l)/2;
            for(ll i=0;i<n;i++) {
                ar[i]=st.calc(i,i+m);
            }
            if(isGood(ar)) {
                r=m;
            }
            else {
                l=m;
            }
        }
        cout<<r-1<<endl;
    }
}


