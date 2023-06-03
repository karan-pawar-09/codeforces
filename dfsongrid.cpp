#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
bool isValid(int x,int y,int n,int m,vector<vector<bool>> &isVisited) {
    if(x<0||x>=n||y<0||y>=m) {
        return false;
    }
    if(isVisited[x][y]) {
        return false;
    }
    return true;
}
void dfs(int x,int y,vector<vector<bool>> &isVisited,int n,int m) {
    int a[4]={-1,0,1,0};
    int b[4]={0,1,0,-1};
    isVisited[x][y]=true;
    cout<<x+1<<" "<<y+1<<endl;
    for(int i=0;i<4;i++) {
        if(isValid(x+a[i],y+b[i],n,m,isVisited)) {
            dfs(x+a[i],y+b[i],isVisited,n,m);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<bool>> isVisited (n,vector<bool> (m,false));
    dfs(0,0,isVisited,n,m);
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