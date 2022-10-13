/*
    author:Karan
    created:26.07.2022 14:14:42
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

const int mx = 1e3+10;
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
int skill[mx];
int salary[mx];
int sum[mx];
int upsalary[mx];

bool comp(pair<int,int> &a, pair<int,int> &b) {
    if(a.first*b.second >= a.second*b.first) return true;
    else return false;
}

void solve() {
    int n,f,u,v;
    cin>>n>>f;
    DSU dsu = DSU(n+10);
    for(int i=0;i<mx;i++) {
        sum[i] = 0;
        upsalary[i]=0;
    }
    for(int i=0; i<n;i++) {
        cin>>u>>v;
        skill[i]=u;
        salary[i]=v;
    }
    int q;
    cin>>q>>f;
    for(int i=0;i<q;i++) {
        cin>>u>>v;
        u--;
        v--;
        dsu.merge(u,v);
    }
    int budget;
    cin>>budget;

    for(int i=0;i<n;i++) {
        sum[dsu.find(i)]+=salary[i];
        upsalary[dsu.find(i)]+=skill[i];
    }
    int res = 0;
    for(int i=0;i<n;i++) {
        int k =0;
        if(sum[i]<=budget) {
            k = skill[i];
        }
        res = max(res, k);
    }
    set<pair<int,int>> s;
    for(int i=0;i<n;i++) {
        s.insert({dsu.find(i),sum[i]});
    }
    set<pair<int,int>> ss;
    for(auto x:s) {
        ss.insert({upsalary[x.first],x.second});
    }
    vector<pair<int,int>> vec(ss.begin(),ss.end());
    sort(all(vec),comp);
    int answer =0 ;
    for(auto x:vec) {
        if(x.second!=0) {
            if((budget-x.second)>=0) {
                answer+=x.first;
                budget-=x.second;
            }
        }
    }
    cout<<answer<<endl;
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