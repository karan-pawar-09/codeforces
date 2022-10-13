// // /*
// //     author:Karan
// //     created:29.09.2022 16:00:57
// // */
// // #if true
// // #pragma GCC target ("avx2")
// // #pragma GCC optimization ("O3")
// // #pragma GCC optimization ("unroll-loops")
// // #include<bits/stdc++.h>
// // using namespace std;
// // #define ll long long
// // #define all(ar) ar.begin(),ar.end()
// // #define endl '\n'
// // #define mset(a,x) memset(a,x,sizeof(a))
// // #endif

// // const ll mod = 1e9+7;
// // const ll N = 1e5;
// // struct nCr{
// //     ll mxN, M; 
// //     vector<ll> fact, ifact; 
// //     inline ll mul(ll a, ll b) { return a *1LL* b % M ;}
// //     ll power(ll a, ll n) {
// //         if(n == 0) return 1 ; 
// //         ll p = power(a, n/2) % M ; 
// //         p = mul(p, p) ;  
// //         return n & 1 ? mul(p, a) : p ; 
// //     }
// //     ll invMod(ll a) {return power(a,M-2);}
// //     void pre() {
// //         fact[0] = 1 ;
// //         for(ll i = 1;i< mxN;++i) fact[i] = mul(i, fact[i-1]) ;
// //         ifact[mxN-1] = invMod(fact[mxN-1]) ; 
// //         for(ll i = mxN-1 ; i>0 ;--i) ifact[i-1] = mul(ifact[i], i) ;
// //     }
// //     nCr(ll _mxN, ll _M) {
// //         mxN = _mxN + 1; 
// //         M = _M ; 
// //         fact.resize(mxN) ; 
// //         ifact.resize(mxN) ;
// //         pre() ;  
// //     }
// //     ll C(ll n, ll r) {
// //         if (n < r || r < 0 || n < 0) return 0;
// //         return mul(fact[n], mul(ifact[r], ifact[n-r])) ;
// //     }
// //     ll factorial(ll a) {
// //         return fact[a];
// //     }
// // };

// // nCr A(N,mod);

// // ll add(ll a, ll b) {
// //     return (a+b)%mod;
// // }

// // ll mul(ll a, ll b) {
// //     return (a*b)%mod;
// // }

// // void solve() {
// //     string s;
// //     cin>>s;
// //     ll answer = 0;
// //     for(ll i=0;i<=9;i++) {
// //         char c = '0'+i;
// //         ll res = 0;
// //         for(auto x: s) {
// //             if(x == ((char) (c+1))) {
// //                 res++;
// //             }
// //         }
// //         ll count = 0;
// //         for(ll j = 0;j<s.size();j++) {
// //             if(s[j] == ((char) (c+1))) {
// //                 res --;
// //             }
// //             if(s[j] == c) {
// //                 count ++;
// //             }
// //             if(count >= 2) {
// //                 if(s[j] == c) {
// //                     answer += mul(count-1, A.C(res, 2));
// //                 }
// //             }
// //         }
// //     }
// //     cout<<answer<<endl;
// // }

// // int32_t main() {
// //     ios_base::sync_with_stdio(false);
// //     cin.tie(NULL);
// //     // freopen("input.txt","r",stdin);
// //     // freopen("output.txt","w",stdout);
// //     ll t=1;
// //     cin>>t;
// //     while(t--) {
// //         solve();
// //     }
// // }


// /*
//     author:Karan
//     created:30.09.2022 16:01:57
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

// const ll mx = 1e5+10;
// vector<pair<ll, ll>> arr[mx];

// ll binarysearch(vector<pair<ll, ll>> &arr, ll x) {
//     ll l = 0;
//     ll r = arr.size();
//     while(l+1 < r) {
//         ll m = (l+r)/2;
//         if(arr[m].first <= x) {
//             l = m;
//         } else {
//             r = m;
//         }
//     }
//     if(arr[l].first <= x) {
//         return l;
//     } else {
//         return -1;
//     }
// }
// void solve() {
//     ll n, m;
//     cin>>n>>m;
//     for(ll i=0;i<mx;i++) {
//         arr[i].clear();
//     }
//     for(ll i=0;i<n;i++) {
//         ll a, b, c;
//         cin>>a>>b>>c;
//         arr[a].push_back({b, c});
//     }
//     for(ll i=0;i<mx;i++) {
//         sort(all(arr[i]));
//     }
//     for(ll i=0;i<mx;i++) {
//         for(ll j=1;j<arr[i].size();j++) {
//             arr[i][j].second = max(arr[i][j].second, arr[i][j-1].second);
//         }
//     }
//     while(m--) {
//         ll a, b;
//         cin>>a>>b;
//         ll res = 0;
//         for(ll i=1;i<=a;i++) {
//             ll ans = binarysearch(arr[i], b);
//             if(ans != -1) {
//                 res = max(res, arr[i][ans].second);
//             }
//         }
//         cout<<res<<endl;
//     }
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