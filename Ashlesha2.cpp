/*
    author:Karan
    created:29.12.2021 14:42:00
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
    int res=0;
    int n=s.size();
    bool ans=true;
    for(int i=0;i<n;i++) {
        if(s[i]=='+') {
            res=2;
        }
        else {
            if(res<=0) {
                ans=false;
                break;
            } else {
                res--;
            }
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
    //cin>>t;
    while(t--) {
        solve();
    }
}