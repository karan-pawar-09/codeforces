/*
    author:Karan
    created:31.05.2023 20:34:25
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

bool isPowerOfTwo(ll x) {
    return x && (!(x & (x - 1)));
}
void solve() {
    ll a, b;
    cin >> a >> b;
    if(a%2 && b%2) {
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
    ll t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}