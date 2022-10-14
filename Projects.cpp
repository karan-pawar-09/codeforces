/*
    author:Karan
    created:14.10.2022 12:36:43
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

ll binarysearch(vector<ll> &arr, ll x) {
    ll l = 0;
    ll r = arr.size();
    while(l+1 < r) {
        ll m = l+(r-l)/2;
        if(arr[m] < x) {
            l = m;
        } else {
            r = m;
        }
    }
    if(arr[l] < x) {
        return l;
    } else {
        return -1;
    }
}

#define item long long

struct segtree {
    ll size;
    vector<item> items;
    item NEUTRAL_ELEMENT=(ll)INT_MIN;
    item merge(item a,item b) {
        return max(a,b);
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
    ll solve(ll k,ll lx, ll rx,ll root,ll l) {
        if(l>=rx) {
            return -1;
        }
        if(items[root]<k) {
            return -1;
        }
        if(rx-lx==1) {
            return lx;
        }
        ll m=lx+(rx-lx)/2;
        ll res=solve(k,lx,m,2*root+1,l);
        if(res==-1) {
            res=solve(k,m,rx,2*root+2,l);
        }
        return res;
    }
    ll solve(ll k,ll l) {
        return solve(k,0,size,0,l);
    }
};

void solve() {
    ll n;
    cin>>n;
    vector<pair<pair<ll, ll>, ll>> arr(n);
    map<ll, ll> M;
    vector<ll> end(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i].first.second>>arr[i].first.first>>arr[i].second;
        end[i] = arr[i].first.first;
    }
    sort(all(arr));
    for(int i=0;i<n;i++) {
        end[i] = arr[i].first.first;
    }
    vector<ll> dp(n+10, 0);
    segtree st;
    st.init(n+10);
    st.build(dp);
    for(ll i=0;i<n;i++) {
        ll start = arr[i].first.second;
        ll finish = arr[i].first.first;
        ll xx = binarysearch(end, start);
        if(xx == -1) {
            st.set(i, arr[i].second);
        } else {
            ll val = st.calc(0, xx+1);
            st.set(i, val+arr[i].second);
        }
    }
    cout<<st.calc(0, n)<<endl;
    
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