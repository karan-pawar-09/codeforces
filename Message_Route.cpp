#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<ll>> arr(n);
    for(int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }   
    vector<int> value(n);
    value.push_back(0);
    queue<int> q;
    vector<bool> used(n,false);
    vector<int> rout(n);
    rout[0]=-1;
    q.push(0);
    used[0]=true;
    while((int)q.size()) {
        int v=q.front();
        q.pop();
        for(auto u:arr[v]) {
            if(!used[u]) {
                used[u]=true;
                q.push(u);
                value[u]=value[v]+1;
                rout[u]=v;
            }
        }
    }
    if(!used[n-1]) {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else {
        vector<int> ans;
        for(int v=n-1;v!=-1;v=rout[v]) {
            ans.push_back(v+1);
        }
        reverse(all(ans));
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++) {
            cout<<ans[i]<<" ";
        }
    }
}