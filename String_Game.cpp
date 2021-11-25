/*
    author:Karan
    created:17.11.2021 20:40:57
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
    int one=0;
    int zero=0;
    int k=0;
    for(int i=1;i<n;i++) {
        if(s[i]!=s[i-1]) {
            k++;
            if(i+1<n) {
                if(s[i+1]!=s[i]) {                    
                    i++;
                }
            }
        }
    }
    if(k%2) {
        cout<<"Alice"<<endl;
    } else {
        cout<<"Bob"<<endl;
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