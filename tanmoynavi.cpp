/*
    author:Karan
    created:19.08.2022 18:33:54
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
    vector<ll> a1(n-1), a2(n-1);
    for(ll i=0;i<n-1;i++) {
        cin>>a1[i];
    }
    for(ll i=0;i<n-1;i++) {
        cin>>a2[i];
    }
    vector<bool> ans(n-1, true);
    DSU dsu = DSU(n+10);
    ll q;
    cin>>q;
    vector<ll> query(q);
    for(ll i=0;i<q;i++) {
        cin>>query[i];
        query[i]--;
        ans[query[i]]=false;
    }
    for(ll i=0;i<n-1;i++) {
        if(ans[i]) {
            dsu.merge(a1[i], a2[i]);
        }
    }
    ll maxi =0;
    vector<int> answer;
    for(ll i=1;i<=n;i++) {
        maxi = max(maxi, dsu.magnitude[dsu.find(i)]);
    }
    answer.push_back(maxi);
    for(ll i=q-1;i>0;i--) {
        dsu.merge(a1[query[i]], a2[query[i]]);
        maxi = max(maxi, dsu.magnitude[dsu.find(a1[query[i]])]);
        answer.push_back(maxi);
    }
    reverse(all(answer));
    for(auto x: answer) {
        cout<<x<<endl;
    }
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