/*
author:Karan
created:17.06.2021 22:14:49
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
const int mx=(int)1e5+7;
vector<int> arr[mx];
int in[mx];
vector<int> ans;

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        in[i]=0;
    }
    for(int i=0;i<=n;i++) {
        arr[i].clear();
    }
    while(m--) {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        arr[a].push_back(b);
        in[b]++;
    }
    kahn(n);
    if(ans.size()==n) {
        for(int i=0;i<n;i++) {
            cout<<ans[i]+1<<" ";
        }
        cout<<endl;
    }
    else {
        cout<<"Sandro fails."<<endl;
    }
}