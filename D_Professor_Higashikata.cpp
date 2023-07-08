/*
    author:Karan
    created:06.07.2023 21:31:29
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

struct DSU {
    vector<ll> parent;
    vector<ll> magnitude;
    DSU(ll n) {
        parent.resize(n+1);
        magnitude.resize(n+1);
        for(ll i=0;i<=n;i++) {
            make_set(i);
        }
    }

    ll find(ll v) {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }

    void make_set(ll v) {
        parent[v] = v;
        magnitude[v] = 1;
    }

    void merge(ll a, ll b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (magnitude[a] < magnitude[b])
                swap(a, b);
            parent[b] = a;
            magnitude[a] += magnitude[b];
        }
    }
};

#define item long long
// struct item {
//     ll seg,pref,suf,sum;
// };
struct segtree {
    ll size;
    vector<item> items;
    item NEUTRAL_ELEMENT= 0LL;
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

void solve() {
    ll n, m, q;
    cin >> n >> m >> q;
    string s;
    cin >> s;
    vector<pair<ll, ll>> arr(m);
    for(ll i = 0; i < m; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    vector<ll> queries(q);
    for(ll i = 0; i < q; i++) {
        cin >> queries[i];
    }
    vector<bool> used(n, false);
    DSU dsu = DSU(n + 10);
    vector<ll> next(n);
    for(ll i = 0; i < n; i++) {
        next[i] = i+1;
    }
    vector<ll> aray;
    for(auto x: s) {
        if(x == '0') aray.push_back(0);
        else aray.push_back(1);
    }
    vector<ll> ind(n, -1);
    ll lvl = 0;
    ll cnt = 0;
    for(ll i = 0; i < m; i++) {
        ll l = arr[i].first;
        ll r = arr[i].second;
        l--;
        r--;
        for(ll j = l; j <= r;) {
            if(!used[j]) {
                used[j] = true;
                ind[j] = lvl++;
                if(j + 1 <= r) {
                    if(!used[j + 1]) {
                        dsu.merge(j, j + 1);
                        next[dsu.find(j + 1)] = next[j + 1];
                    }
                }
                j++;
            } else {
                j = next[dsu.find(j)];
            }
        }
    }
    cnt = lvl;
    for(auto &x: ind) {
        if(x == -1) {
            x = lvl++;
        }   
    }
    
    vector<ll> dp(n);
    for(ll i = 0; i < n; i++) {
        dp[ind[i]] = aray[i];
    }

    ll totalones = 0;
    for(auto x: dp) {
        if(x == 1) totalones++;
    }

    segtree st;
    st.init(n + 1);
    st.build(dp);

    for(ll i = 0; i < q; i++) {
        ll X = queries[i];
        X--;
        if(dp[ind[X]] == 1) {
            totalones--;
            dp[ind[X]] = 0;
            st.set(ind[X], 0);
        } else {
            totalones++;
            dp[ind[X]] = 1;
            st.set(ind[X], 1);
        }
        ll has = st.calc(0, min(totalones, cnt));
        cout<<min(cnt, totalones) - has<<endl;
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