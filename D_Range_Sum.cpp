// a[n-1]^2+a[0]^2-2*a[n-1]*a[0] = sum(a[0] to a[n-1])
/*

a[n-1]^2 + a[0]^2 = a[0]+ ... + a[n-1]+2*a[n-1]*a[0]
10^12 + 1 - 2*(1e6) = 2 + 3+ 4+ ........

n^2 +1 - 2*n*a = ()

100

(11-1)^2 = 1+11 + 
10^2 - 12
100 - 12 - 88 -> 


1e5

//999950884


*/


/*
    author:Karan
    created:05.12.2022 11:44:48
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

const int mx = 999950884;
/*

(1e9-1)^2 = 1+1e9 + 2+3+.....
    2*3+4+........ (n-2)*(n-1)/2;
*/

int binarysearch(int n) {
    int l = 1;
    int r = 1e9;
    while(l+1 < r) {
        
    }
}
void solve() {
    int n;
    cin>>n;

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