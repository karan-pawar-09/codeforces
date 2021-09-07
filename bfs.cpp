#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> adj;
    int n;
    int s;
    queue<int> q;
    vector<bool> used(n,false);
    vector<int> d(n),p(n);
    q.push(s);
    used[s]=true;
    p[s]=-1;
    while(!q.empty()) {
        int v=q.front();
        q.pop();
        for(int u:adj[v]) {
            if(!used[u]) {
                used[u]=true;
                q.push(u);
                d[u]=d[v]+1;
                p[u]=v;
            }
        }
    }
    if(!used[u]) {
        cout<<"NO PATH"<<endl;
    }
    else {
        vector<int>path;
        for(int v=u;v!=-1;v=p[v]) {
            path.push_back();
        }
        reverse(all(path));
        cout<<"Path: ";
        for(int v:path) {
            cout<<v<<" ";
        }
    }
}


