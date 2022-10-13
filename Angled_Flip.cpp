/*
    author:Karan
    created:17.08.2022 14:33:33
*/
#if true
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
#define mset(a,x) memset(a,x,sizeof(a))
#endif

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> oneblack, twoblack, onewhite, twowhite;
    vector<vector<int>> a1(n, vector<int> (m));
    vector<vector<int>> a2(n, vector<int> (m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>a1[i][j];
            if((i+j)%2) {
                oneblack.push_back(a1[i][j]);
            } else {
                onewhite.push_back(a1[i][j]);
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>a2[i][j];
            if((i+j)%2) {
                twoblack.push_back(a2[i][j]);
            } else {
                twowhite.push_back(a2[i][j]);
            }
        }
    }
    //TODO: corner case n==1 or m==1
    sort(all(oneblack));
    sort(all(twoblack));
    sort(all(onewhite));
    sort(all(twowhite));
    if(oneblack==twoblack && onewhite==twowhite) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}