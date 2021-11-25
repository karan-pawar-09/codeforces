/*
    author:Karan
    created:22.11.2021 21:04:21
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

const int mx=1010;
const int inf=1e9+7;
vector<int> no;
int dp[mx];
multiset<int> parent[mx];

string decToBinary(int n) {
    int binaryNum[32];
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    string ans;
    for (int j = i - 1; j >= 0; j--) {
        if(binaryNum[j]==1) ans.push_back('1');
        else ans.push_back('0');
    }
    return ans;
}

bool is_good(int i) {
    string str=decToBinary(i);
     int len = str.length();
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1])
            return false;
    }
    return true;
}

void solve() {
    int n;
    cin>>n;
    if(dp[n]<=12) {
        cout<<dp[n]<<endl;
        for(auto x:parent[n]) {
            cout<<x<<" ";
        }
    }
    else {
        cout<<-1;
    }
    cout<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    mset(dp,inf);
    for(int i=1;i<mx;i++) {
        if(is_good(i)) {
            no.push_back(i);
        }
    }
    dp[0]=0;
    for(int i=0;i<mx;i++) {
        if(dp[i]!=inf) {
            for(int j=0;j<no.size();j++) {
                if((i+no[j])<mx) {
                    if((dp[i]+1)<dp[i+no[j]]) {
                        dp[i+no[j]]=dp[i]+1;
                        multiset<int> temp=parent[i];
                        temp.insert(no[j]);
                        parent[i+no[j]]=temp;
                    }
                }
            }
        }
    }
    while(t--) {
        solve();
    }
}