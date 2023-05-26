/*
    author:Karan
    created:25.05.2023 14:11:28
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

void solve() {
    int n, q;
    cin >> n >> q;
    vector<set<int>> graph(3e5+10);
    int con[(int)3e5+10];
    int count = n;
    while(q--) {
        int a, b, c;
        cin >> a;
        if(a==1) {
            cin >> b >> c;
            if(con[a]==0) {
                count--;
            }
            if(con[b]==0) {
                count--;
            }
            con[a]++;
            con[b]++;
            graph[a].insert(b);
            graph[b].insert(a);
        } else {
            cin >> b;
            if(con[b] != 0) {
                con[b] = 0;
                count++;
            }
            for(auto x: graph[b]) {
                graph[x].erase(b);
                con[x]--;
                if(con[x]==0) {
                    count++;
                }
            }
            graph[b].clear();
        }
        cout<<count<<endl;
    }
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