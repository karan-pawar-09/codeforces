// /*
//     author:Karan
//     created:24.06.2023 18:04:23
// */
// #if true
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define all(ar) ar.begin(),ar.end()
// #define endl '\n'
// #define mset(a,x) memset(a,x,sizeof(a))
// #endif

// const ll mod=998244353;
// const ll N = 1e6 + 10;

// ll power(long long x, unsigned ll y, ll mod) {
//     ll res = 1; 
//     x = x % mod;   
//     if (x == 0) return 0;  
//     while (y > 0) {        
//         if (y & 1)
//             res = (res*x) % mod; 
//         y = y>>1;
//         x = (x*x) % mod;
//     }
//     return res;
// }

// struct nCr{
//     ll mxN, M; 
//     vector<ll> fact, ifact; 
//     inline ll mul(ll a, ll b) { return a *1LL* b % M ;}
//     ll power(ll a, ll n) {
//         if(n == 0) return 1 ; 
//         ll p = power(a, n/2) % M ; 
//         p = mul(p, p) ;  
//         return n & 1 ? mul(p, a) : p ; 
//     }
//     ll invMod(ll a) {return power(a,M-2);}
//     void pre() {
//         fact[0] = 1 ;
//         for(ll i = 1;i< mxN;++i) fact[i] = mul(i, fact[i-1]) ;
//         ifact[mxN-1] = invMod(fact[mxN-1]) ; 
//         for(ll i = mxN-1 ; i>0 ;--i) ifact[i-1] = mul(ifact[i], i) ;
//     }
//     nCr(ll _mxN, ll _M) {
//         mxN = _mxN + 1; 
//         M = _M ; 
//         fact.resize(mxN) ; 
//         ifact.resize(mxN) ;
//         pre() ;  
//     }
//     ll C(ll n, ll r) {
//         if (n < r || r < 0 || n < 0) return 0;
//         return mul(fact[n], mul(ifact[r], ifact[n-r])) ;
//     }
//     ll factorial(ll a) {
//         return fact[a];
//     }
// };
// nCr A(N,mod);

// ll sub(ll a, ll b) {
//     return ((a % mod) - (b % mod) + mod) % mod;
// }
// ll mul(ll a, ll b) {
//     return ((a % mod) * (b % mod)) % mod;
// }
// ll mul(ll a, ll b, ll c) {
//     return ((a % mod) * (mul(c, b))) % mod;
// }
// ll add(ll a, ll b) {
//     return ((a % mod) + (b % mod)) % mod;
// }
// int countValidDistributions(int N, int M) {
//     std::vector<std::vector<int>> dp(N + 1, std::vector<int>(M, 0));

//     // Base case: one person
//     for (int j = 0; j < M; j++) {
//         dp[1][j] = 1;
//     }

//     // Dynamic programming
//     for (int i = 2; i <= N; i++) {
//         for (int j = 0; j < M; j++) {
//             for (int k = 0; k < M; k++) {
//                 if (k != j) {
//                     dp[i][j] = add(dp[i][j], dp[i - 1][k]);
//                 }
//             }
//         }
//     }

//     // Calculate the final result
//     int result = 0;
//     for (int j = 0; j < M; j++) {
//         result = add(result, dp[N][j]);
//     }
//     return result;
// }
// void solve() {
//     ll n, m;
//     cin >> n >> m;
//     ll res = add(mul(m, power(m-1, n-2, mod)), mul(m, power(m-1, n-2, mod), m - 2));
//     cout<<countValidDistributions(n, m)<<endl;
// }

// int32_t main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     // freopen("input.txt","r",stdin);
//     // freopen("output.txt","w",stdout);
//     ll t=1;
//     //cin>>t;
//     while(t--) {
//         solve();
//     }
// }

