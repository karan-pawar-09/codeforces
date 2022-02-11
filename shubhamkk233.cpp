#include<bits/stdc++.h>
 using namespace std;

 const int maxn=5e3+5;

 #define int long long
 const int mod=1e9+7;

 int n,k,dp[maxn][maxn],sum[maxn];
 string s;

 main()  {

    cin>>n>>k;
    cin>>s;
    s=" "+s;
    dp[0][0]=1;
    sum[0]=1;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=k;j++)
        {
            dp[i][j]=(sum[j]*(int)(s[i]-'a'))%mod;
            for (int l=i-1;l>=0;l--)
            {
                int val=j-(int)(i-l)*(n-i+1);
                if(val<0) break;
                dp[i][j]=(dp[i][j]+(dp[l][val]*(int)('z'-s[i]))%mod)%mod ;
            }
           sum[j]=(sum[j]+dp[i][j])%mod;
        }

        int res(0);

        for (int i=0;i<=n;i++)
            res=(res+dp[i][k])%mod;

    cout<<res<<endl;

    return 0;
    }
