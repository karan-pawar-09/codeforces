/*
    author:Karan
    created:15.01.2022 21:45:07
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

const int mx=1e5+7;
set<int,int> s;
vector<int> arr[mx];
int dist;
int len[mx];
void dfs(int node, int par,int ht) {
    dist=max(dist,ht);
    len[node]=ht;
    for(auto x:arr[node]) {
        if(x!=par) {
            dfs(x,node,ht+1);
        }
    }
}
void solve() {
    int n;
    cin>>n;
    s.clear();
    dist=0;
    int u,v;
    for(int i=0;i<=n;i++) {
        arr[i].clear();
    }
    vector<int> freq(n+1,0);
    vector<pair<int,int>> ar(n);
    for(int i=0;i<n-1;i++) {
        cin>>u>>v;
        ar[i]={u,v};
        if(u>v) {
            swap(u,v);
        }
        freq[u]++;
        freq[v]++;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    bool can=false;
    int root;
    for(int i=1;i<=n;i++) {
        if(freq[i]>= (n/2)) {
            can=true;
            root=i;
            break;
        }
    }
    if(can) {
        dfs(root,-1,0);
        if(dist>2 or arr[root].size()>2) {
            cout<<-1<<endl;
        } else {
            for(int i=0;i<n-1;i++) {
                bool k=false;
                if(ar[i].first==root or ar[i].second==root) {
                    int distandce=max(len[ar[i].second],len[ar[i].first]);
                    if(!k) {
                        cout<<2<<" ";
                        k=true;
                    }
                    else cout<<3<<" ";
                } else {
                    if(len[ar[i].first]==1) {
                        
                    }
                }
            }
            cout<<endl;
        }
    } else {
        cout<<-1<<endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}