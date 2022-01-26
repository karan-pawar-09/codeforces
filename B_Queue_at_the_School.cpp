/*
    author:Karan
    created:20.01.2022 22:26:39
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
    int n,t;
    cin>>n>>t;
    string s;
    cin>>s;
    for(int j=0;j<t;j++) {
        for(int i=0;i<n-1;i++) {
            if(s[i]=='B' and s[i+1]=='G') {
                s[i]='G';
                s[i+1]='B';
                i++;
            }
        }
    }
    cout<<s<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}