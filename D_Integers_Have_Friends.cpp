/*
author:Karan
created:01.08.2021 21:47:35
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

#define item long long

struct segtree {
    ll size;
    vector<ll> items;
    item NEUTRAL_ELEMENT=(ll)-1;
    item merge(item &a,item &b) {
        if(a == -1) return b;
		if(b == -1) return a;
        return __gcd(a,b);
    }
    item single(ll &v) {
        return v;       
    }
    void init(ll &n) {
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
    void set(ll &i,ll &v,ll x,ll lx,ll rx) {
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
    void set(ll &i,ll &v) {
        set(i,v,0,0,size);
    }
    item calc(ll &l,ll &r,ll x,ll lx,ll rx) {
        if(lx>=r|l>=rx) return NEUTRAL_ELEMENT;
        if(lx>=l&&rx<=r) return items[x];
        ll m=lx+(rx-lx)/2;
        item s1=calc(l,r,2*x+1,lx,m);
        item s2=calc(l,r,2*x+2,m,rx);
        return merge(s1,s2);
    }
    item calc(ll &l,ll &r) {
        return calc(l,r,0,0,size);
    }
};

segtree st;
ll n;

bool isGood(ll i,ll j) {
    
    if(st.calc(i,j)>1) return true;
    
    return false;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {        
        cin>>n;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++) {
            cin>>arr[i];
        }
        if(n==1) {
            cout<<1<<endl;
        }
        else {
            vector<ll> diff(n-1);
            for(ll i=1;i<n;i++) {
                diff[i-1]=abs(arr[i]-arr[i-1]);
            }
            n--;
            st.init(n);
            st.build(diff);
            ll ans=0;
            for(ll i=0,j=0;i<n&&j<n;) {
                if(isGood(i,j+1)) {
                    ans=max(ans,j+1-i);
                    j++;
                }
                else {
                    i++;
                    if(j<i)
                        j=i;
                }
            }
            
            cout<<ans+1<<endl;
        }
    }
}