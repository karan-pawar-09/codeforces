/*
    author:Karan
    created:20.02.2022 13:54:38
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

int n,m;
int a[4]={1,-1,0,0};
int b[4]={0,0,1,-1};

bool isGood(int i,int j, vector<string> &arr,vector<vector<bool>> &visited) {
    if(i<0 or i>=n or j<0 or j>=m) {
        return false;
    }
    if(arr[i][j]=='X' or visited[i][j]) {
        return false;
    }
    return true;
}

void dfs(int i, int j, vector<string> &arr,vector<vector<bool>> &visited) {
    visited[i][j]=true;
    for(int k=0;k<4;k++) {
        int nexti=i+a[k];
        int nextj=j+b[k];
        if(isGood(nexti,nextj,arr,visited)) {
            dfs(nexti,nextj,arr,visited);
        }
    }
}

void solve() {
    cin>>n>>m;
    vector<string> arr(n);
    vector<vector<bool>> visited(n,vector<bool> (m,false));
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    int starti,startj;
    for(int i=0; i<n;i++) {
        for(int j=0; j<m; j++) {
            if(arr[i][j]=='A') {
                starti=i;
                startj=j;
            }
            if(arr[i][j]=='>') {
                int k=j+1;
                while(k<m and arr[i][k]!= '>' and arr[i][k]!='<' and arr[i][k]!='^' and arr[i][k]!='v' and arr[i][k]!='X') {
                    if(arr[i][k]=='A') {
                        starti=i;
                        startj=k;
                    }
                    arr[i][k]='X';
                    k++;
                }
            } else if( arr[i][j]=='<') {
                int k=j-1;
                while(k>=0 and arr[i][k]!= '>' and arr[i][k]!='<' and arr[i][k]!='^' and arr[i][k]!='v' and arr[i][k]!='X') {
                    if(arr[i][k]=='A') {
                        starti=i;
                        startj=k;
                    }
                    arr[i][k]='X';
                    k--;
                }
            } else if(arr[i][j] == 'v' ) {
                int k=i+1;
                while(k<n and arr[i][k]!= '>' and arr[i][k]!='<' and arr[i][k]!='^' and arr[i][k]!='v' and arr[i][k]!='X') {
                    if(arr[k][j]=='A') {
                        starti=k;
                        startj=j;
                    }
                    arr[k][j]='X';
                    k++;
                }
            } else if(arr[i][j]== '^') {
                int k=i-1;
                while(k>=0 and arr[i][k]!= '>' and arr[i][k]!='<' and arr[i][k]!='^' and arr[i][k]!='v' and arr[i][k]!='X') {
                    if(arr[k][j]=='A') {
                        starti=k;
                        startj=j;
                    }
                    arr[k][j]='X';
                    k--;
                }
            }
        }
    }
    if(isGood(starti,startj,arr,visited))
        dfs(starti,startj,arr,visited); 
    if(visited[n-1][m-1]) {
        cout<<true<<endl;
    } else  {
        cout<<false<<endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}