/*
    author:Karan
    created:15.10.2022 22:28:15
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



ll power(long long x, unsigned ll y) {
    ll res = 1; 
    x = x ;   
    if (x == 0) return 0;  
    while (y > 0) {        
        if (y & 1)
            res = (res*x); 
        y = y>>1;
        x = (x*x);
    }
    return res;
}
void solve() {
    ll n, k;
    cin>>n>>k;
    for(ll i=1;i<=k;i++) {
        ll res = power(10, i);
        ll rem = n%res;
        ll rem1 = res-rem;
        //cout<<i<<" "<<res<<" "<<rem<<" "<<rem1<<endl;
        if((2*rem) >= res) {
            n += rem1;
        } else {
            n -= rem;
        }
    }
    cout<<n<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}