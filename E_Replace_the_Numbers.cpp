/*
    author:Karan
    created:18.12.2021 21:51:13
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
        for(ll i=1;i<=n;i++) {
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

void solve() {
    int q;
    cin>>q;
    DSU tr = DSU(5e5+10);
    vector<int> val(5e5+10);
    vector<int> kkk(5e5+10);
    int temp=0;
    while(q--) {
        int a,x,y;
        cin>>a;
        if(a==1) {
            cin>>x;
            kkk[temp]=x;
            temp++;
        }
        else {
            cin>>x>>y;
            tr.merge(x,y);
            val[tr.find(x)]=y;
        }
    }
    for(int i=0;i<temp;i++) {
        cout<<val[tr.find(kkk[i])]<<" ";
    }
    cout<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}