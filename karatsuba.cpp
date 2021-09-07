/*
author:Karan
created:04.06.2021 12:52:24
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

vector<int> breaking(vector<int> a,int l, int r) {
    vector<int> ans;
    for(int i=l;i<r;i++) {
        ans.push_back(a[i]);
    }
    return ans;
}
vector<int> Mul(vector<int> a,vector<int> b,int n,int l,int r) {
    if(r-l==1) {
        vector<int> ans;
        ans.push_back(a[l]*b[l]);
        return ans;
    }
    int m=(r+l)/2;
    vector<int> D0=breaking(a,l,m);
    vector<int> D1=breaking(a,m,r);  
    vector<int> E0=breaking(b,l,m);
    vector<int> E1=breaking(b,m,r); 

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int a[max(n,m)];
    int b[max(n,m)];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<m;i++) {
        cin>>b[i];
    }
    vector<int> c(n+m);

}