/*
author:Karan
created:13.06.2021 14:56:17
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

string ans;
vector<vector<int>> dp;
void lcs (string s,string t,int n,int m) {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(s[i-1]==t[j-1]) {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int karan;
    cin>>karan;
    while(karan--) {
        string s,t;
        cin>>s>>t;
        int n=s.size();
        int m=t.size();
        dp.resize(n+1,vector<int> (m+1,0));
        for(int i=0;i<=n;i++) {
            for(int j=0;j<m;j++) {
                dp[i][j]=0;
            }
        }
        lcs(s,t,n,m);
        int i=n;
        int j=m;
        while(i&&j) {
            if(dp[i][j]>dp[i-1][j]&&dp[i][j]>dp[i][j-1]) {
                ans+=s[i-1];
                i--;
                j--;
            }
            else {
                if(dp[i-1][j]>dp[i][j-1]) {
                    i--;
                }
                else {
                    j--;
                }
            }
        }
        reverse(all(ans));
        if(ans==s||ans==t) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }   
}