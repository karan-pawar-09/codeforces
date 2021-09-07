/*
author:Karan
created:11.08.2021 17:36:20
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll h,w,n;
    cin>>h>>w>>n;
    int x[n],y[n];
    set<int> sx,sy;
    map<int,int> mx,my;

    for(int i=0;i<n;i++) {
        cin >> x[i] >> y[i];
        sx.insert(x[i]);
        sy.insert(y[i]);
    }

    int c=1;
    for(auto it:sx)
        mx[it]=c++;

    c=1;
    for(auto it:sy)
        my[it]=c++;

    for(int i=0;i<n;i++)
        cout << mx[x[i]] << " " << my[y[i]] << endl;
}