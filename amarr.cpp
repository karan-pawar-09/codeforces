/*
    author:Karan
    created:08.03.2022 21:41:46
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
    int n,m;
    cin>>n>>m;
    
    char *impossible ="Not Possible";
    char *ans= malloc(n+1);
    for(int i=0;i<n;i++) {
        ans[i]='A';
    }
    m--;
    ans[n]='\0';
    int i=n-1;
    long num=1;
    while(num<=m) {
        if(num&m) {
            ans[i]='B';
            i--;
        }
        num=num<<1;
        if(i<=0 && num<=m) {
            return impossible;
        }
        i--;
        if(i<0 && num<=m) {
            return impossible;
        }
    }
    return ans;
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