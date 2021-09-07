/*
author:Karan
created:08.06.2021 17:12:25
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const int mx=(int)1e5;
int parent[mx];
int mag[mx];

void make_node(int a) {
    parent[a]=a;
    mag[a]=1;
}
int find_set(int a) {
    if(parent[a]==a) {
        return a;
    }
    return parent[a]=find_set(parent[a]);
}
void merge(int a,int b) {
    a=find_set(a);
    b=find_set(b);
    if(a!=b) {
        if(mag[a]<mag[b]) {
            swap(a,b);
        }
        parent[b]=a;
        mag[a]+=mag[b];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) {
        make_node(i);
    }
    int u,v;
    while(m--) {
        cin>>u>>v;
    }   
    vector<pair<string,pair<int,int>>> arr;
    while(k--) {
        string s;
        cin>>s>>u>>v;
        arr.push_back({s,{u,v}});
    }
    reverse(all(arr));
    vector<string> ans;
    for(int i=0;i<arr.size();i++) {
        if(arr[i].first=="ask") {
            find_set(arr[i].second.first)==find_set(arr[i].second.second)?ans.push_back("YES"):ans.push_back("NO");
        }
        else {
            merge(arr[i].second.first,arr[i].second.second);
        }
    }
    reverse(all(ans));
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<endl;
    }
}