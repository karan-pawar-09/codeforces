/*
    author:Karan
    created:07.09.2021 18:16:42
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(m);
    vector<bool> visited(n+1,false);
    vector<int> freq(n+1,0);
    vector<vector<pair<int,int>>> indices(n+1);
    int k,a;
    for(int i=0;i<m;i++) {
        cin>>k;
        for(int j=0;j<k;j++) {
            cin>>a;
            indices[a].push_back({i,j});
            arr[i].push_back(a);
        }
    }
    vector<int> index(m,0);
    queue<pair<int,int>> q;
    for(int i=0;i<m;i++) {
        freq[arr[i][index[i]]]++;
        if(freq[arr[i][index[i]]]>1) {
            q.push(indices[arr[i][index[i]]][0]);
            q.push(indices[arr[i][index[i]]][1]);
            freq[arr[i][index[i]]]=0;
        }
    }
    while(q.size()) {
        pair<int,int> loc=q.front();
        q.pop();
        visited[arr[loc.first][loc.second]]=true;
        if(loc.second+1<arr[loc.first].size()) {
            freq[arr[loc.first][loc.second+1]]++;
            if(freq[arr[loc.first][loc.second+1]]>1) {
                q.push(indices[arr[loc.first][loc.second+1]][1]);
                q.push(indices[arr[loc.first][loc.second+1]][0]);
                freq[arr[loc.first][loc.second+1]]=0;
            }
        }
    }
    bool ans=true;
    for(int i=1;i<=n;i++) {
        if(!visited[i]) {
            ans=false;
            break;
        }
    }
    if(ans) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}