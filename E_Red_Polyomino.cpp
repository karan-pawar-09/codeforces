/*
author:Karan
created:26.07.2021 17:01:29
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

ll n,k,ans;

set<vector<vector<char>>> s;

ll adda[4]={1,-1,0,0};
ll addb[4]={0,0,-1,1};

bool isGood(ll x,ll y){
    return 0<=x && x<=n-1 && 0<=y && y<=n-1;
}

void dfs(ll no,vector<vector<char>> &s) {    
    if(no==0) {
        ans++;
        return;
    }
    vector<pair<ll,ll>> restore;
    for(ll i=0;i<n;i++) {
        for(ll j=0;j<n;j++) {
            if(s[i][j]=='.') {

                bool flag=false;

                for(ll z=0;z<4;z++) {
                    ll nexta=adda[z]+i;
                    ll nextb=addb[z]+j;
                    if(isGood(nexta,nextb)&&s[nexta][nextb]=='@') {
                        flag=true;
                    }
                }
                if(flag) {
                    s[i][j]='@';
                    dfs(no-1,s);
                    s[i][j]='#';
                    restore.push_back({i,j});
                }
            }
        }
    }
    for(auto x:restore) {
        s[x.first][x.second]='.';
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin>>n>>k;
    ans=0;
    vector<vector<char>> s(n,vector<char> (n));

    for(ll i=0;i<n;i++) {
        for(ll j=0;j<n;j++) {
            cin>>s[i][j];
        }
    }
    for(ll i=0;i<n;i++) {
        for(ll j=0;j<n;j++) {
            if(s[i][j]=='.') {
                s[i][j]='@';
                dfs(k-1,s);
                s[i][j]='#';
            }
        }
    }   
    cout<<ans<<endl;
}