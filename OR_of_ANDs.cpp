#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
 
struct segtree {
    ll size;
    vector<ll> sums;
    void init(ll n) {
        size=1;
        while(size<n) {
            size*=2;
        }
        sums.assign(2*size,0LL);
    }
    void build(vector<ll> &a,ll x,ll lx,ll rx) {
        if(rx-lx==1) {
            if(lx<((ll)a.size())) {
                sums[x]=a[lx];
            }
            return;
        }
        ll m=lx+(rx-lx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        sums[x]=sums[2*x+1]|sums[2*x+2];
    }
    void build(vector<ll> &a) {
        build(a,0,0,size);
    }
    void set(ll i,ll v,ll x,ll lx,ll rx) {
        if(rx-lx==1) {
            sums[x]=v;
            return;
        }
        ll m=lx+(rx-lx)/2;
        if(i<m) {
            set(i,v,2*x+1,lx,m);
        }
        else {
            set(i,v,2*x+2,m,rx);
        }
        sums[x]=sums[2*x+1]|sums[2*x+2];
    }
    void set(ll i,ll v) {
        set(i,v,0,0,size);
    }
    ll sum(ll l,ll r,ll x,ll lx,ll rx) {
        if(lx>=r|l>=rx) return 0;
        if(lx>=l&&rx<=r) return sums[x];
        ll m=lx+(rx-lx)/2;
        ll s1=sum(l,r,2*x+1,lx,m);
        ll s2=sum(l,r,2*x+2,m,rx);
        return s1|s2;
    }
    ll sum(ll l,ll r) {
        return sum(l,r,0,0,size);
    }
};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        ll n,m; 
        cin>>n>>m;
        segtree st;
        st.init(n);
        vector<ll> a(n);
        for(ll i=0;i<n;i++) {
            cin>>a[i];
        }
        st.build(a);
        cout<<st.sum(0,n)<<endl;
        while(m--) {
          
            ll i,v;
            cin>>i>>v;
            i--;
            st.set(i,v);            
            cout<<st.sum(0,n)<<endl;
            
        }
    }    
}