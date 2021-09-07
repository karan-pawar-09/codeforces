/*
author:Karan
created:21.06.2021 16:36:53
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

bool isGood(int i,int j,int n) {
    if(i<0||i>n||j<0||j>n) {
        return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<vector<bool>> dp(n+1,vector<bool> (n+1,true));
    dp[0][0]=false;
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=n;j++) {
            if(i!=0||j!=0) {
                bool temp=true;
                for(int k=0;k<=3;k++) {
                    for(int p=0;p<=3;p++) {
                        if(k+p<=3&&isGood(i-k,j-p,n)) {
                            temp&=dp[i-k][j-p];
                        }
                    }
                }
                if(temp) {
                    dp[i][j]=false;
                }
            }            
        }
    }
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=n;j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

}

