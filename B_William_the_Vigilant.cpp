/*
    author:Karan
    created:28.11.2021 20:22:49
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
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    int res=0;
    vector<bool> dp(n,false);
    for(int i=1;i<n-1;i++) {
        if(s[i]=='b' and s[i-1]=='a' and s[i+1]=='c') {
            res++;
            dp[i]=dp[i-1]=dp[i+1]=true;
        }
    }
    int a;
    char c;
    while(q--) {
        cin>>a>>c;
        a--;
        if(s[a]!=c) {
            if(dp[a]) {
                res--;
                if(s[a]=='a') {
                    dp[a]=dp[a+1]=dp[a+2]=false;
                }
                else if(s[a]=='b') {
                    dp[a-1]=dp[a]=dp[a+1]=false;
                }
                else {
                    dp[a-2]=dp[a-1]=dp[a]=false;
                }
            }
            if(!dp[a]) {
                if(c=='a') {
                    if(s[a+1]=='b' and s[a+2]=='c') {
                        res++;
                        dp[a]=dp[a+1]=dp[a+2]=true;
                    }
                }
                else if(c=='b') {
                    if(s[a-1]=='a' and s[a+1]=='c') {
                        res++;
                        dp[a]=dp[a-1]=dp[a+1]=true;
                    }
                }
                else {
                    if(s[a-2]=='a' and s[a-1]=='b') {
                        res++;
                        dp[a-2]=dp[a-1]=dp[a]=true;
                    }
                }
            }
        }
        s[a]=c;
        cout<<res<<endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    while(t--) {
        solve();
    }
}