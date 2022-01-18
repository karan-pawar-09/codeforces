/*
    author:Karan
    created:15.01.2022 20:06:47
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

const int inf=1e9+7;

void solve() {
    int n,m,r,c;
    cin>>n>>m>>r>>c;
    vector<vector<char>> arr(n,vector<char> (m));
    vector<bool> row(n,false);
    vector<bool> col(m,false);
    bool tc=false;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>arr[i][j];
            if(arr[i][j]=='B') {
                if(i==(r-1) and j==(c-1)) {
                    tc=true;
                }
                row[i]=true;
                col[j]=true;
            }
        }
    }
    r--;
    c--;
    int dist=inf;
    for(int i=0;i<n;i++) {
        if(row[i])
            dist=min(dist,abs(r-i));
    }
    for(int j=0;j<m;j++) {
        if(col[j]) {
            dist=min(dist,abs(c-j));
        }
    }
    if(tc) cout<<0<<endl;
    else {
        if(dist==0) {
            cout<<1<<endl;
        } else if(dist==inf) {
            cout<<-1<<endl;
        } else cout<<2<<endl;
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