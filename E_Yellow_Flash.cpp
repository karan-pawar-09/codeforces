#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=1e9+5;
void solve() {
    int n,k;
    cin>>n>>k;
    map<int,vector<int>>map;
    for(int i=0;i<k;i++) {
        int a,b;
        cin>>a>>b;
        map[a].push_back(b);
    }
    vector<int>dp(n+1,INF);   
    dp[0]=0;
    if(map.find(0)!=map.end()) {
        for(int j=0;j<map[0].size();j++) {
            dp[map[0][j]]=min(dp[map[0][j]],dp[0]);
        }
    }
    for(int i=1;i<=n;i++) {
        dp[i]=min(dp[i],dp[i-1]+1);
        if(map.find(i)!=map.end()) {
            for(int j=0;j<map[i].size();j++) {
                dp[map[i][j]]=min(dp[map[i][j]],dp[i]);
            }
        }
    } 
    cout<<dp[n]<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
}