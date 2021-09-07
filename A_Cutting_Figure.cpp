/*
author:Karan
created:06.06.2021 13:32:18
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int n,m;
char arr[100][100];
int visited[100][100];
int tin[100][100];
int low[100][100];
int a[4] = {-1, 0, 1, 0};
int b[4] = {0, 1, 0, -1};
int timer;
int answer;
int isValid(int x,int y) {
    if(x<0||x>n-1||y<0||y>m-1) {
        return 0;
    }
    if(arr[x][y]=='#') {
        return 0;
    }
    return 1;
}

void dfs(int x,int y,int px,int py) {
    visited[x][y]=1;
    tin[x][y]=low[x][y]=timer++;
    int children=0;
    for(int i=0;i<4;i++) {
        if(isValid(x+a[i],y+b[i])) {
            if(x+a[i]==px&&y+b[i]==py) continue;
            if(visited[x+a[i]][y+b[i]]) {
                low[x][y]=min(low[x][y],tin[x+a[i]][y+b[i]]);
            }
            else {
                dfs(x+a[i],y+b[i],x,y);
                low[x][y]=min(low[x][y],low[x+a[i]][y+b[i]]);
                if(low[x+a[i]][y+b[i]]>=tin[x][y]&&px!=-1&&py!=-1) {
                    answer++;
                }
                ++children;
            }
            
        }
    }
    if(px==-1&&py==-1&&children>1) {
        answer++;
    }
   
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    timer=0;
    answer=0;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            char k;
            cin>>k;
            if(k=='#') {
                arr[i][j]='.';
            }
            else {
                arr[i][j]='#';
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j]=='.'&&visited[i][j]==false) {                
                dfs(i,j,-1,-1);
            }
        }
    }  
    cout<<answer<<endl;  
}