/*
author:Karan
created:13.06.2021 22:51:37
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,a;
    cin>>n;
    vector<int> first(n+1);
    vector<vector<bool>> adj(n+1,vector<bool> (n+1,false));
    vector<int> oddq,evenq;
    cout<<"? "<<1<<endl;
    cout.flush();
    int odd=0;
    int even=0;
    for(int i=1;i<=n;i++) {
        cin>>a;
        first[i]=a;
        if(a%2) {
            odd++;
            oddq.push_back(i);
        }
        else {
            even++;
            if(i!=1)
                evenq.push_back(i);
        }
    }
    vector<int> qu;
    if(odd>=even) {
        qu=evenq;
    }
    else {
        qu=oddq;
    }
    if(even<=odd) {
        for(int j=1;j<=n;j++) {
            if(first[j]==1) {
                adj[1][j]=true;
            }
        }
    }
    for(int i=0;i<qu.size();i++) {     
        cout<<"? "<<qu[i]<<endl;
        cout.flush();
        for(int j=1;j<=n;j++) {
            cin>>a;
            if(a==1) {
                adj[qu[i]][j]=true;
            }
        }
               
    }

    cout<<"!"<<endl;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(adj[i][j]) {
                cout<<i<<" "<<j<<endl;
            }
        }
    }
    cout.flush();    
}