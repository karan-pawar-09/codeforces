/*
    author:Karan
    created:17.11.2022 10:18:45
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'



const int mx=(int)1e6+7;
vector<int> arr[mx];
int in[mx];
vector<int> ans;
bool visited[mx];
int freq[200];
int res;

void dfs(int v, string &s) {
    visited[v] = true;
    freq[s[v]]++;
    int childs = 0;
    for (int u : arr[v]) {
        if (!visited[u]) {
            childs++;
            dfs(u, s);
        }
    }
    if(childs==0) {
        int maxi = 0;
        for(int i='a';i<='z';i++) {
            maxi = max(maxi, freq[i]);
        }
        res = max(res, maxi);
    }
    freq[s[v]]--;
}

void kahn(int n) {
    queue<int> q;
    for(int i=0;i<n;i++) {
        if(in[i]==0) {
            q.push(i);
        }
    }
    while(q.size()) {
        int v=q.front();
        q.pop();
        ans.push_back(v);
        for(int x:arr[v]) {
            in[x]--;
            if(!in[x]) {
                q.push(x);
            }
        }
    }
}

int beauty(int n, int m, string s, vector<int> x, vector<int> y) {
    res = 0;
    for(int i=0;i<n;i++) {
        in[i]=0;
    }
    for(int i=0;i<=n;i++) {
        visited[i] = false;
        arr[i].clear();
    }
    for(int i=0;i<200;i++) {
        freq[i] = 0;
    }
    for(int i=0;i<m;i++) {
        int aa, bb;
        aa = x[i];
        bb = y[i];
        aa--;
        bb--;
        arr[aa].push_back(bb);
        in[bb]++;
    }
    kahn(n);

    if(ans.size()==n) {
        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                dfs(i, s);
            }
        }
        return res;
    }
    else {
        return -1;
    }
}

//DONE!

void solve() {
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<int> a(m);
    vector<int> b(m);
    for(int i=0;i<m;i++) {
        cin>>a[i];
    }
    for(int i=0;i<m;i++) {
        cin>>b[i];
    }
    cout<<beauty(n, m, s, a, b)<<endl;
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