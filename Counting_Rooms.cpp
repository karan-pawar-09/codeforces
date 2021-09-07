#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
int visited[1000][1000];
char arr[1000][1000];
int n,m;
int isValid(int a,int b) {
    if(a<0||a>n-1||b<0||b>m-1) {
        return 0;
    }
    if(visited[a][b]==true||arr[a][b]!='.') {
        return 0;
    }
    return 1;
}
void dfs(int a,int b) {
    visited[a][b]=1;

    if(isValid(a+1,b)) {
        dfs(a+1,b);
    }
    if(isValid(a,b+1)) {
        dfs(a,b+1);
    }
    if(isValid(a-1,b)) {
        dfs(a-1,b);
    }
    if(isValid(a,b-1)) {
        dfs(a,b-1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    cin>>n>>m;   
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j]=='.'&&visited[i][j]==false) {                
                ans++;
                dfs(i,j);
            }
        }
    }    
    cout<<ans<<endl;
}