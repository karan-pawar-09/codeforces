/*
    author:Karan
    created:25.11.2022 00:24:40
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
    ll n, m;
    cin >> n >> m;
    ll c2 = 0;
    ll c5 = 0;
    ll x = n;
    while(x%2 == 0) {
        c2++;
        x/=2;
    }
    while(x%5 == 0) {
        c5++;
        x/=5;
    }
    ll k = 1;
    while(c2 < c5) {
        if(k*2 <= m) {
            k *= 2;
            c2++;
        } else {
            break;
        }
    }
    while(c5 < c2) {
        if((k*5) <= m) {
            k *= 5;
            c5++;
        } else {
            break;
        }
    }
    while((k*10) <= m) {
        k*=10;
    }
    k *= (m/k);
    cout<< k*n<<endl;
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