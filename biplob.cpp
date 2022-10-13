/*
    author:Karan
    created:15.07.2022 20:23:38
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
    int n,c,q;
    cin>>n>>c>>q;
    string s;
    cin>>s;
    vector<set<int>> dp(150);
    for(int i=0;i<n;i++) {
        dp[s[i]].insert(i+1);
    }
    int prev=n;
    for(int i=0;i<c;i++) {
        int l,r;
        cin>>l>>r;
        for(int j=l;j<=r;j++) {
            prev++;
            for(int k='a';k<='z';k++) {
                if(dp[k].find(j)!=dp[k].end()) {
                    dp[k].insert(prev);
                }
            }
        }
    }
    for(int i=0;i<q;i++) {
        int x;
        cin>>x;
        for(int i='a';i<='z';i++) {
            if(dp[i].find(x)!=dp[i].end()) {
                cout<<(char)('a'+(i-'a'))<<endl;
            }
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}