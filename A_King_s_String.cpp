/*
    author:Karan 
    sch.Id: 1912134
    created:04.01.2022 18:01:30
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
    string s;
    cin>>s;
    bool ans=true;
    int n=s.size();
    for(int i=0;i<s.size();i++) {
        if(s[i]=='a' and s[n-1-i]!='b') {
            ans=false;
            break;
        }
        if(s[i]=='b' and s[n-1-i] != 'a') {
            ans=false;
            break;
        }
    }
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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