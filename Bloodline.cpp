/*
    author:Karan
    created:10.06.2023 15:20:17
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

const int mx = 2e5+10;
void solve() {
    int n, k;
    cin >> n >> k;
    if(n%(k+1) %2 || (n%(k+1)) == k) {
        cout<<"Shivansh"<<endl;
    } else {
        cout<<"Tina"<<endl;
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



