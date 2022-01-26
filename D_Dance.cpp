/*
    author:Karan
    created:24.01.2022 10:43:49
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

const int mx=1e6+10;
int req;
int res;
int n;

vector<int> arr[28];
int dp[mx];

int rec(int k, int no) {
    if(no==req) {
        return k;
    }
    int ans=0;
    int x=no;
    int req=0;
    for(int i=0;i<2*n;i++) {
        if(no&(1<<i)) {
            res|=(1<<i);
        }
    }
    if(dp[req]!=-1) return dp[req];
    for(int i=0;i<(2*n)-1;i++) {       
        for(int j=i;j<(2*n)-1;j++) {
            if((x&(1<<i))==0 and (x&(1<<(j+1)))==0) {
                x^=(1<<i);
                x^=(1<<(j+1));
                int temp=k^arr[i][j-i];
                ans=max(ans,rec(temp,x));
                x^=(1<<i);
                x^=(1<<(j+1));
            }
        }     
    }
    return dp[no]=ans;
}
void solve() {
    res=0;
    cin>>n;
    mset(dp,-1);
    req=(1<<(2*n))-1;
    for(int i=0;i<(2*n)-1;i++) {
        arr[i].clear();
    }
    for(int i=0;i<(2*n)-1;i++) {
        for(int j=i;j<(2*n)-1;j++) {
            int p;
            cin>>p;
            arr[i].push_back(p);
        }
    }
    cout<<rec(0,0)<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}