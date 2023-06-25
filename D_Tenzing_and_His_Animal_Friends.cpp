/*
    author:Karan
    created:24.06.2023 20:45:50
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

const ll INF = 1e18;

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

ll count(string & s) {
    ll ct = 0;
    for(auto x: s) {
        if(x == '1') ct++;
    }
    return ct;
}
void solve() {
    ll n, m;
    cin >> n >> m;
    DSU dsu = DSU(n+10);
    vector<pair<pair<ll, ll>, ll>> arr;
    for(ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        arr.push_back({{a, b}, c});
        dsu.merge(a, b);
    }
    if(dsu.find(1) != dsu.find(n)) {
        cout<<"inf"<<endl;
    } else {
        vector<pair<string, ll>> ans;
        vector<ll> time(n+1, 0);
        set<ll> pos, neg;
        string s;
        for(ll i = 1; i < n; i++) {
            pos.insert(i);
            s.push_back('1');
        }
        neg.insert(n);
        s.push_back('0');
        while(count(s)) {
            vector<ll> can(n+1, INF);
            ll ctt = 0;
            for(ll i = 1; i <= n; i++) {
                if(pos.count(i)) {
                    s[i-1] = '1';
                    ctt++;
                } else {
                    s[i-1] = '0';
                }
            }
            if(ctt == 0 || s[0] == '0') break;
            for(ll i = 0; i < m; i++) {
                if((pos.count(arr[i].first.first) && neg.count(arr[i].first.second))) {
                    can[arr[i].first.first] = min(can[arr[i].first.first], arr[i].second - time[arr[i].first.second]);
                 }
                 if((pos.count(arr[i].first.second) && neg.count(arr[i].first.first))) {
                    can[arr[i].first.second] = min(can[arr[i].first.second], arr[i].second - time[arr[i].first.first]);
                 }
            }
            
            ll mini = INF;
            for(ll i = 1; i <= n; i++) {
                if(pos.count(i)) {
                    mini = min(mini, can[i]);
                }
            }
            ans.push_back({s, mini});
            for(auto x: neg) {
                time[x] += mini;
            }
            for(ll i = 1; i <= n; i++) {
                if(can[i] == mini) {
                    pos.erase(i);
                    neg.insert(i);
                }
            }
        }
        ll res = 0;
        for(auto x: ans) res += x.second;
        cout<<res<<" "<<ans.size()<<endl;
        for(auto x: ans) {
            cout<<x.first<<" "<<x.second<<endl;
        }
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