/*
    author:Karan
    created:26.11.2021 21:05:43
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
    cin>>n;
    string s;
    cin>>s;
    int b=0;
    int w=0;
    
    for(int i=1;i<n;i++) {
        if(s[i]!=s[i-1]) {
            if(s[i-1]=='B') {
                b++;
            }
            else {
                w++;
            }            
        }
        if(i==n-1) {
            if(s[i]=='B') {
                b++;
            } else w++;
        }
    }
    cout<<min(w,b)<<endl;
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