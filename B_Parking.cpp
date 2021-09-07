/*
author:Karan
created:21.07.2021 21:21:20
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const int mx=3e5+7;
int parent[mx]; 

void make(int i) {
    parent[i]=i;
}
int find(int a) {
    if(parent[a]==a) return a;
    else return parent[a]=find(parent[a]);
}
void merge(int a,int b) {
    int p=find(a);
    int q=find(b);
    if(q!=p) {
        parent[a]=parent[b];
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=1;i<=n+1;i++) {
        make(i);
    }
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        cout<<find(arr[i])<<" ";
        if(find(arr[i])==n) {
            merge(find(arr[i]),1);
        }
        else merge(find(arr[i]),find(arr[i])+1);
    }
}