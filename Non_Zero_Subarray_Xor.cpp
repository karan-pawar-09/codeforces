/*
    author:Karan
    created:26.01.2022 20:33:16
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

void maxLengthArr(int n) {    
    for (int i = 1; i<=n; i++) {     
        cout << (i ^ (i-1)) << " ";
    }
    cout<<endl;
}
void solve() {
    int n;
    cin>>n;
    maxLengthArr(n);
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