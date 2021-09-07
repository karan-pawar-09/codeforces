/*
author:Karan
created:07.06.2021 13:14:39
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
const int mx=(int)2e5+7;
vector<int> parent;
vector<int> magnitude;
vector<int> add;
void make_set(int v) {
    parent[v] = v;
    magnitude[v]=1;
    add[v]=0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if(magnitude[a]<magnitude[b]) {
            swap(a,b);
        }
        parent[b] = a;
        magnitude[a] += magnitude[b];
        add[b]-=add[a];
    }
        
}
int get_value(int a) {
    if(parent[a]==a) {
        return add[a];
    }
    else {
        return add[a]+get_value(parent[a]);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    parent.resize(n);
    magnitude.resize(n);
    add.resize(n);
    for(int i=0;i<n;i++) {
        make_set(i);
    }
    while(m--) {
        string s;
        int u,v;
        cin>>s;
        if(s=="join") {
            cin>>u>>v;
            u--;
            v--;
            union_sets(u,v);
        }
        else if(s=="add") {
            cin>>u>>v;
            u--;
            add[find_set(u)]+=v;
        }
        else {
            cin>>u;
            u--;
            cout<<get_value(u)<<endl;
        }
    }
}

