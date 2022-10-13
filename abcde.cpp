/*
    author:Karan
    created:05.10.2022 18:47:38
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
    int n, m;
    cin>>n>>m;
    vector<vector<int>> matA(n,vector<int> (m));
    const int inf = -1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(i==0) {
                if(j!=0) {
                    if(matA[i][j-1] == inf) {
                        matA[i][j] = inf;
                    } else {
                        matA[i][j] = matA[i][j-1] * matA[i][j];
                    }
                } 
                if(matA[i][j] > 106) {
                    matA[i][j] = inf;
                }
            }
            else if(j==0) {
                if(i!=0) {
                    if(matA[i-1][j] == inf) {
                        matA[i][j] = inf;
                    } else {
                        matA[i][j] = matA[i-1][j] * matA[i][j];
                    }
                }
                if(matA[i][j] > 106) {
                    matA[i][j] = inf;
                }
            }
            else {
                if(matA[i-1][j]== inf || matA[i][j-1]==inf) {
                    matA[i][j] = inf;
                } else {
                    matA[i][j] = ((matA[i-1][j] * matA[i][j-1]) /(matA[i-1][j-1])) * matA[i][j];
                }
                if(matA[i][j] > 106) {
                    matA[i][j] = inf;
                }
            }
            if(matA[i][j] > 106) {
                matA[i][j] = inf;
            }
        }
    }
    
    int ans = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(matA[i][j] <= maxK && matA[i][j] != inf) {
                ans ++;
            }
        }
    }
    return ans;
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}