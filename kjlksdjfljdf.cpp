
/*
    author:Karan
    created:28.05.2023 11:29:25
*/
#if true
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
#define mset(a,x) memset(a,x,sizeof(a))
#endif

#define ll int

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

int minCost(int n, vector<int>& cuts) {
    sort(cuts.begin(), cuts.end());
    vector<int> arr;
    int prev = 0;
    for(auto x: cuts) {
        arr.push_back(x-prev);
        prev = x;
    }
    arr.push_back(n-prev);
    int N = arr.size();
    DSU dsu = DSU(N+1);
    vector<int> sz(N+1, 1);
    int price = 0;
    while(true) {
        int mini = 1e9+10;
        int a, b;
        bool used = false;
        for(int i=0;i<N ;) {
            int prev = i - arr[i];
            if(prev >= 0) {
                used = true;
                if(arr[dsu.find(i)]+arr[dsu.find(prev)] < mini) {
                    mini = arr[dsu.find(i)]+arr[dsu.find(prev)];
                    a = i;
                    b = prev;
                }
            }
            i += arr[i];
        }
        if(!used) {
            break;
        }
        int size = arr[a] + arr[b];
        cout<<size<<endl;
        price += size;
        dsu.merge(a, b);
        arr[dsu.find(a)] = size;
    }
    return price + n;
}

void solve() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> arr(m);
    for(int i=0;i<m;i++) {
        cin >> arr[i];
    }
    cout<<minCost(n, arr)<<endl;
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