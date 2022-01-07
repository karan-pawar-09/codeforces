/*
    author:Karan
    created:04.01.2022 22:38:59
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

ll n,m;

bool isOk(ll x,ll y) {
    if(x==n and y==m) return false;
    if(x==0 and y==0) return false;
    if(x==0 and y==m) return false;
    if(x==n and y==0) return false;
    return true;
}
void solve() {
    cin>>n>>m;
    vector<vector<bool>> isThere(n+1,vector<bool> (m+1,false));
    isThere[0][0]=true;
    ll x=1;
    ll y=1;
    bool xinc=true;
    bool yinc=true;
    while(1) {
        isThere[x][y]=true;
        if(!isOk(x,y)) break;
        if(x==n) {
            xinc=false;
        }
        if(x==0) {
            xinc=true;
        }
        if(y==m) {
            yinc=false;
        } 
        if(y==0) {
            yinc=true;
        }
        if(xinc) x++;
        else x--;
        if(yinc) y++;
        else y--;    
         
    }    
    ll q;
    cin>>q;
    while(q--) {
        ll a,b;
        cin>>a>>b;
        if(isThere[a][b]) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}