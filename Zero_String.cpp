/*
    author:Karan
    created:02.02.2023 14:08:24
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
    int ones = 0;
    int zeros = 0;
    for(auto x: s) {
        if(x=='0') {
            zeros++;
        } else {
            ones++;
        }
    }
    if(zeros >= ones) {
        cout<<ones<<endl;
    } else {
        cout<<zeros+1<<endl;
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