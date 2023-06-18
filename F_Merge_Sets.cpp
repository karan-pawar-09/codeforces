/*

1 2 3 8 => 4
1 3 4 6 => 3
2 4 6 8 => 5


1 2 3 4 6 8 => 2 * 1 + 2 * 3 + 2 + 6 


2 4 6 8 => 1 * 2 + 2 + 3 + 1 * 1 + 4 

*/


/*
    author:Karan
    created:17.06.2023 18:53:49
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

ll binarysearch(vector<pair<ll, ll>> & arr, ll no) {
    ll l = 0;
    ll r = arr.size();
    while(l+1 < r) {
        ll m = l + (r - l)/2;
        if(arr[m].first < no) {
            l = m;
        } else {
            r = m;
        }
    }
    if(arr[l].first < no) return l;
    else return -1;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> arr(n, vector<ll> (m));
    vector<ll> ar;
    vector<pair<ll, ll>> tmp;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            cin>>arr[i][j];
            ar.push_back(arr[i][j]);
            tmp.push_back({arr[i][j], ar.size()-1});
        }
    }
    map<ll, set<ll>> M;
    vector<pair<ll, ll>> pp = tmp;
    sort(all(tmp));
    for(auto x: tmp) {
        M[x.first].insert(x.second);
        cout<<x.first<<" "<<x.second<<endl;
    }
    vector<ll> dp(ar.size(), 0);

    segtree st;
    st.init(ar.size()+10);
    st.build(dp);


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