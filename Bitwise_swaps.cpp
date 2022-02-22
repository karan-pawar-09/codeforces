/*
    author:Karan
    created:13.02.2022 11:38:35
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
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    vector<ll> ar=arr;
    DSU dsu=DSU(n+10);
    for(ll i=31;i>=0;i--) {
        vector<ll> index,val;
        for(ll j=0;j<n;j++) {
            if(arr[j]&(1<<i)) {
                index.push_back(j);
                val.push_back(arr[j]);
                if(index.size()) {
                    dsu.merge(j,index[0]);
                }
            }
        }
        
    }

    map<int,vector<int>> indx;
    map<int,vector<int>> value;
    for(int i=0;i<n;i++) {
        indx[dsu.find(i)].push_back(i);
        value[dsu.find(i)].push_back(arr[i]);
    }
    for(auto x:indx) {
        int key=x.first;
        sort(all(value[key]));
        for(int i=0;i<x.second.size();i++) {
            arr[x.second[i]]=value[key][i];
        }
    }
    bool ans=true;
    for(ll i=1;i<n;i++) {
        if(arr[i]<arr[i-1]) {
            ans=false;
            break;
        }
    }
    if(ans) {
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
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