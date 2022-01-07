/*
    author:Karan
    created:28.12.2021 19:15:30
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
    int n,m,a,b,y,z;
    cin>>m>>n>>a>>b>>y>>z;
    bool k=true;
    int ans=0;
    int hor=1;
    int ver=1;
    while(a!=y and b!=z) {
        if(hor==1) {
            if(ver==1) {
                if(a==m and b==n) {
                    a--;
                    b--;
                    hor=0;
                    ver=0;
                }
                else if(a==m) {
                    a--;
                    b++;
                    hor=0;
                } 
                else if(b==n) {
                    b--;
                    a++;
                    ver=0;
                } else {
                    a++;
                    b++;
                }
            } else {
                if(a==m and b==1) {
                    a--;
                    b++;
                    hor=0;
                    ver=1;
                } else if(a==m) {
                    a--;
                    b--;
                    hor=0;
                } else if(b==1) {
                    b++;
                    a++;
                    ver=1;
                } else {
                    a++;
                    b--;
                }
            }
        }
        else {
            if(ver==1) {
                if(a==1 and b==n) {
                    a++;
                    b--;
                    hor=1;
                    ver=0;
                } else if(a==1) {
                    a++;
                    b++;
                    hor=1;
                } else if(b==n) {
                    b--;
                    a--;
                    ver=0;
                } else {
                    a--;
                    b++;
                }
            } else {
                if(a==1 and b==1) {
                    a++;
                    b++;
                    hor=1;
                    ver=1;
                } else if(a==1) {
                    a++;
                    b--;
                    hor=1;
                } else if(b==1) {
                    b++;
                    a--;
                    ver=1;
                } else {
                    a--;
                    b--;
                }
            }
        }
        ans++;
    }
    cout<<ans<<endl;
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