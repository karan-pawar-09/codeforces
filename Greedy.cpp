/*
    author:Karan
    created:09.06.2023 21:57:35
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    if((s.size()) % 2) {
        cout<<"NO"<<endl;
    } else {
        int same = 1;
        vector<int> ar;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) {
                same++;
            } else {
                ar.push_back(same);
                same = 1;
            }
        }
        ar.push_back(same);
        vector<vector<bool>> dp(ar.size()+1, vector<bool> (n+1, false));
        vector<vector<pair<int, int>>> backtrack(ar.size()+1, vector<pair<int, int>> (n+1, {-1, -1}));
        dp[0][0] = true;
        for(int i = 1; i <= ar.size(); i++) {
            for(int j = 0; j <= n; j++) {
                if((j + ar[i-1]) <= n && dp[i-1][j]) {
                    dp[i][j + ar[i-1]] = true;
                    backtrack[i][j + ar[i-1]] = {i-1, j};
                }
                if((j - ar[i-1]) >= 0 && dp[i-1][j]) {
                    dp[i][j - ar[i - 1]] = true;
                    backtrack[i][j - ar[i - 1]] = {i-1, j};
                }
            }
        }
        
        if(dp[ar.size()][0]) {
            cout<<"YES"<<endl;
            vector<int> ans;
            const pair<int, int> invalid = {-1, -1};
            int prevj = 0;
            for(pair<int, int> i = {ar.size(), 0}; i  != invalid; i = backtrack[i.first][i.second]) {
                ans.push_back(prevj - i.second);
                prevj = i.second;
            }
            for(int i= ans.size()-1; i > 0; i--) {
                for(int j = 0; j < abs(ans[i]);j++) {
                    if(ans[i] > 0) cout<<'(';
                    else cout<<')';
                }
            }
            cout<<endl;
        }
        else cout<<"NO"<<endl;
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