/*
    author:Karan
    created:27.11.2021 21:46:26
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

const int mod=998244353;
void extendedgcd(ll a, ll b, ll*arr) {if (b == 0) {arr[0] = 1; arr[1] = 0; arr[2] = a; return;} extendedgcd(b, a % b, arr); ll x = arr[1]; arr[1] = arr[0] - arr[1] * (a / b); arr[0] = x; return;}
ll mi_copr(ll a, ll m) { ll* arr = new ll;  extendedgcd(a,m,arr);  return ((arr[0]+m)%m);}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}

void solve() {
    ll n;   cin>>n;
    ll sum = mod_mul(n,n+1,mod);
    sum *= mi_copr(2,mod);
    ll res = mod_mul(sum,sum,mod)*mi_copr(n,mod);
    cout<<(res%mod)<<endl;
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