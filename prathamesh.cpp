/*
author:Karan
created:15.08.2021 15:26:34
*/
#include<iostream>
#include<vector>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

vector<vector<int>> arr;
vector<vector<pair<int,int>>> par;
vector<vector<bool>> used;

int n,m;

bool isValid(int a,int b) {
    if(a<0||a>=n||b<0||b>=m) {
        return false;
    }
    if(used[a][b]==true||arr[a][b]!=1) {
        return false;
    }
    return true;
}

void dfs(int a,int b) {
    used[a][b]=1;
  
    if(isValid(a+1,b)) {
        dfs(a+1,b);
        par[a+1][b]={a,b};
    }
    if(isValid(a,b+1)) {
        dfs(a,b+1);
        par[a][b+1]={a,b};
    }
    if(isValid(a-1,b)) {
        dfs(a-1,b);
        par[a-1][b]={a,b};
    }
    if(isValid(a,b-1)) {
        dfs(a,b-1);
        par[a][b-1]={a,b};
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin>>n>>m;
    arr.resize(n,vector<int> (m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }
    pair<int,int> start,end;
    pair<int,int> invalid={-1,-1};
    cin>>start.first>>start.second>>end.first>>end.second;
    par.resize(n,vector<pair<int,int>> (m,invalid));
    used.resize(n,vector<bool>(m,false));

    dfs(start.first,start.second);

    vector<pair<int,int>> ans;

    for(pair<int,int> i=end;i!=invalid;i=par[i.first][i.second]) {
        ans.push_back(i);
    }
    for(auto x:ans) {
        cout<<"<"<<x.first<<","<<x.second<<">";
    }
}