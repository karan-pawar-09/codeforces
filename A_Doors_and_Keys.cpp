/*
    author:Karan
    created:22.02.2022 20:07:42
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
    map<char,bool> M;
    M['r']=M['g']=M['b']=false;
    bool ans=true;
    for(int i=0;i<s.size();i++) {
        if(s[i]>='a' and s[i]<='z') {
            M[s[i]]=true;
        }
        else {
            if(s[i]=='R') {
                if(!M['r']) {
                    ans=false;
                }
            } else if(s[i]=='G') {
                if(!M['g']) {
                    ans=false;
                }
            } else {
                if(!M['b']) {
                    ans=false;
                }
            }
        }
    }
    if(!ans) {
        cout<<"NO"<<endl;
    } else {
        cout<<"YES"<<endl;
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