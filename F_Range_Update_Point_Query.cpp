/*
    author:Karan
    created:03.02.2023 20:31:08
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
// struct item {
//     ll seg,pref,suf,sum;
// };
struct segtree {
    ll size;
    vector<item> items;
    item NEUTRAL_ELEMENT=0;
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
};

ll find(ll n, ll times) {
    n = n;
    while(times > 0 && n >= 10) {
        times--;
        string temp = to_string(n);
        ll pp = 0;
        for(auto x: temp) {
            pp += x-'0';
        }
        n = pp;
    }
    return n;
}

void solve() {
    ll n, m;
    cin>>n>>m;
    vector<ll> arr(n);
    vector<ll> dp(n, 0);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    segtree st;
    st.init(n+10);
    st.build(dp);
    while(m--) {
        ll a, b, c;
        cin>>a;
        if(a==1) {
            cin>>b>>c;
            b--;
            c--;
            dp[b]++;
            st.set(b, dp[b]);
            if(c+1 < n) {
                dp[c+1]--;
                st.set(c+1, dp[c+1]);
            }
        } else {
            cin>>b;
            ll times = st.calc(0, b);
            cout<<find(arr[b-1], times)<<endl;
        }
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