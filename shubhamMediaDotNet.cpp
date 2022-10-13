#include<bits/stdc++.h>
using namespace std;

const int mod = (int)1e9+7;
const int maxn = 2005;
int dp[maxn][maxn],dp2[maxn][maxn];

int main() {
    int n,k; cin >> n >> k;
    string s; cin >> s;
    dp[n][0]=1;  dp2[n][0]=1;
    
    for(int i=n-1;i>=0;i--) {
        for(int j=0;j<=k;j++) {
            dp2[i][j] = dp2[i+1][j] + (s[i]-'a')*1LL*dp[i+1][j] % mod;
            dp2[i][j] %= mod;
            dp[i][j] = dp2[i][j];
            int ll=i;
            int rr = n-1;
            while(ll<=rr) {
                int currcnt = (ll-i+1)*(n-ll);
                if(currcnt>j) break;
                dp[i][j] += dp[ll+1][j-currcnt]*1LL*(25-(s[ll]-'a'))%mod;
                dp[i][j] %= mod;
                ll++;
            }
            while(ll<=rr) {
                int currcnt = (rr-i+1)*(n-rr);
                if(currcnt>j) break;
                dp[i][j] += dp[rr+1][j-currcnt]*1LL*(25-(s[rr]-'a'))%mod;
                dp[i][j] %= mod;
                rr--;
            }
        }
    }
    cout << dp[0][k] << endl;
    return 0;
}