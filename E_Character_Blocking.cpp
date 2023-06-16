/*
    author:Karan
    created:09.06.2023 11:28:34
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

# define item bool


struct segtree {
    ll size;
    vector<item> items;
    item NEUTRAL_ELEMENT={true};
    item merge(item a,item b) {
        return a&b;
    }
    item single(pair<char, char> & v) {
        return (v.first == v.second);
    }
    void init(ll n) {
        size=1;
        while(size<n) {
            size*=2;
        }
        items.resize(2*size);
    }
    void build(vector<pair<char,char>> &a,ll x,ll lx,ll rx) {
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
    void build(vector<pair<char, char>> &a) {
        build(a,0,0,size);
    }
    void set(ll i,pair<char, char> v,ll x,ll lx,ll rx) {
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
    void set(ll i,pair<char, char> v) {
        set(i,v,0,0,size);
    }
    item calc(ll l,ll r,ll x,ll lx,ll rx) {
        if(lx>=r|l>=rx) {
            return NEUTRAL_ELEMENT;
        }
        if(lx>=l&&rx<=r) {
            return items[x];
        }
        ll m=lx+(rx-lx)/2;
        item s1=calc(l,r,2*x+1,lx,m);
        item s2=calc(l,r,2*x+2,m,rx);
        item tempp = merge(s1, s2);
        return merge(s1,s2);
    }
    item calc(ll l,ll r) {
        return calc(l,r,0,0,size);
    }
};

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    vector<pair<char,char>> arr;
    for(ll i=0;i<s1.size();i++) {
        arr.push_back({s1[i], s2[i]});
    }
    ll t, q;
    cin >> t >> q;
    segtree st;
    st.init(s1.size()+1);
    st.build(arr);
    map<int, int> M;
    for(ll time = 1; time <= q; time++) {
        if(M.find(time) != M.end()) {
            ll index = M[time];
            arr[index] = {s1[index], s2[index]};
            st.set(index, {s1[index], s2[index]});
        }
        ll a;
        cin >> a;
        if(a == 1) {
            ll b;
            cin >> b;
            b--;
            st.set(b, {'#', '#'});
            arr[b] = {'#', '#'};
            M[time+t] = b;
        } else if(a == 2) {
            ll b, c, d, e;
            cin >> b >> c >> d >> e;
            c--;
            e--;
            char temp1;
            if(b == 1) {
                temp1 = arr[c].first;
            } else {
                temp1 = arr[c].second;
            }
            char temp2;
            if(d == 1) {
                temp2 = arr[e].first;
            } else {
                temp2 = arr[e].second;
            }
            swap(temp1, temp2);
            if(b == 1) {
                arr[c].first = temp1;
            } else {
                arr[c].second = temp1;
            }

            if(d == 1) {
                arr[e].first = temp2;
            } else {
                arr[e].second = temp2;
            }

            st.set(c, arr[c]);
            st.set(e, arr[e]); 
        } else {
            st.calc(0, s1.size())?cout<<"YES"<<endl:cout<<"NO"<<endl;
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