/*
author:Karan
created:08.07.2021 17:51:28
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

struct LCA {
    vector<ll> height, euler, first, segtree;
    vector<bool> visited;
    ll n;

    LCA(vector<vector<ll>> &adj, ll root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        ll m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<ll>> &adj, ll node, ll h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(ll node, ll b, ll e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            ll mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            ll l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    ll query(ll node, ll b, ll e, ll L, ll R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        ll mid = (b + e) >> 1;

        ll left = query(node << 1, b, mid, L, R);
        ll right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    ll lca(ll u, ll v) {
        ll left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};

void solve(ll n, LCA st) {
    ll k;
    cin>>k;
    vector<ll> arr(k);
    for(ll i=0;i<k;i++) {
        cin>>arr[i];
        arr[i]--;
    }
    vector<ll> lvl(n+1,0);
    bool ans=true;
    ll lim=0;
    ll minlvl=(ll)1e9+7;
    for(ll i=1;i<k;i++) {
        ll no=st.lca(arr[0],arr[i]);
        lvl[st.height[no]]++;
        minlvl=min(minlvl,st.height[no]);
        if(lvl[st.height[no]]>2) {
            ans=false;
            break;
        }
        if(lvl[st.height[no]]==2) {
            if(st.height[no]!=minlvl) {
                ans=false;
            }
        }
        if(!ans) break;
    }
    
    ans?cout<<"YES"<<endl:cout<<"NO"<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        vector<vector<ll>> grid(n);
        for(ll i=0;i<n-1;i++) {
            ll a,b;
            cin>>a>>b;
            a--;
            b--;
            grid[a].push_back(b);
            grid[b].push_back(a);
        }
        LCA st=LCA(grid);
        ll q;
        cin>>q;
        while(q--) {
            solve(n, st);
        }
    }
}