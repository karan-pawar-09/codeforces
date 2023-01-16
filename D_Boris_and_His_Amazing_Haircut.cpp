/*
    author:Karan
    created:11.01.2023 11:17:00
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
        parent.resize(n + 1);
        magnitude.resize(n + 1);
        for (ll i = 0;i <= n;i++) {
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
    cin >> n;

    vector<ll> a(n), b(n), l(n), r(n);
    set<int> s;
    unordered_map<ll, ll> available;
    unordered_map<ll, ll> maxi; 

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(i);
    }
    for (ll i = 0; i < n; i++) {
        cin >> b[i];
        maxi[i] = b[i];
        l[i] = i;
        r[i] = i;
    }
    
    DSU dsu = DSU(n);

    ll m;
    cin >> m;

    for (ll i = 0; i < m; i++) {
        ll temp;
        cin >> temp;
        available[temp]++;
    }

    // Special case

    for (ll i = 0; i < n; i++) {
        if (a[i] < b[i]) {
            cout << "NO" << endl;
            return;
        }
    }

    //Solution

    vector<ll> p(n);
    iota(p.begin(), p.end(), 0);
    sort(all(p), [&](ll i, ll j) {
        return b[i] < b[j];
    });

    for(ll i = 0; i < n; i++) {
        if(s.size() == 0) {
            break;
        }
        if(a[p[i]] == b[p[i]]) {
            continue;
            s.erase(p[i]);
        }
        if(dsu.find(p[i]) == p[i]) {
            available[b[p[i]]] --;
            if(available[b[p[i]]] < 0) {
                cout<<"NO"<<endl;
                return;
            }
            ll rt, lt;
            rt = p[i] + 1;
            lt = p[i] - 1;
            s.erase(p[i]);
            while(rt < n && maxi[dsu.find(rt)] <= b[p[i]]) {
                s.erase(rt);
                r[dsu.find(p[i])] = max(r[dsu.find(rt)], p[i]);
                l[dsu.find(p[i])] = min(l[dsu.find(rt)], p[i]);
                dsu.merge(p[i], rt);
                maxi[dsu.find(p[i])] = max(maxi[dsu.find(p[i])], b[p[i]]);
                rt = r[dsu.find(rt)] + 1;
            }
            while(lt >= 0 && maxi[dsu.find(lt)] <= b[p[i]]) {
                s.erase(lt);
                l[dsu.find(p[i])] = min(l[dsu.find(lt)], p[i]);
                r[dsu.find(p[i])] = max(r[dsu.find(lt)], p[i]);
                dsu.merge(p[i], lt);
                maxi[dsu.find(p[i])] = max(maxi[dsu.find(p[i])], b[p[i]]);
                lt = l[dsu.find(lt)] - 1;
            }
        }
    }
    
    for(auto x: available) {
        if(x.second < 0) {
            cout << "NO" << endl;
            return;
        }
    }
    
    cout << "YES" << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
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