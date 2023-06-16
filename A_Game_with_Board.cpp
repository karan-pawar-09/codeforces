/*
    author:Karan
    created:12.06.2023 20:08:34
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
    if(n == 1) {
        cout<<"Alice"<<endl;
        return;
    }
    if(n >=2 && n <= 4) {
        cout<<"Bob"<<endl;
        return;
    } 
    cout<<"Alice"<<endl;
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