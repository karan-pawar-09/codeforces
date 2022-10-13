/*
    author:Karan
    created:05.09.2022 18:22:25
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
    int x, y;
    cin>>x>>y;
    if(x%y==0) {
        cout<< x  <<endl;
    } else {
        x *= 10;
        int t = 10;
        while( true) {
            int rem = x%y;
            if(rem == 0) {
                rem = y;
            }
            int p = y-rem;
            if(p < t) {
                cout<<x+p<<endl;
                return;
            }
            x *= 10;
            t *= 10;
        }
        
    }
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