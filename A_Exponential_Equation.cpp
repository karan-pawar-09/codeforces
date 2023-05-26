// /*
//     author:Karan
//     created:29.01.2023 20:09:01
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

// //x^y * y + y^x*x  == n


// ll power(long long x, unsigned ll y) {
//     ll res = 1; 
//     x = x;   
//     if (x == 0) return 0;  
//     while (y > 0) {        
//         if (y & 1)
//             res = (res*x); 
//         y = y>>1;
//         x = (x*x);
//     }
//     return res;
// }

// void solve() {
//     ll n;
//     cin>>n;
//     if(n%2 == 0) {
//         cout<<1<<" "<<n/2<<endl;
//         return;
//     }
//     for(ll i=1;i<=15;i++) {
//         for(ll j=1;j<=15;j++) {
//             ll k = power(i, j) * j + power(j, i) * i;
//             if(k == n) {
//                 cout<<i<<" "<<j<<endl;
//                 return;
//             }
//         }
//     }
//     cout<<-1<<endl;
// }

// int32_t main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     // freopen("input.txt","r",stdin);
//     // freopen("output.txt","w",stdout);
//     ll t=1;
//     cin>>t;
//     while(t--) {
//         solve();
//     }
// }


#include <bits/stdc++.h>
using namespace std;
#define ll long long
const char nl = '\n';

template<class t, class u> bool pkmin(t &a, u b) {if (b < a) {a = b; return true;} else return false;}
template<class t, class u> bool pkmax(t &a, u b) {if (a < b) {a = b; return true;} else return false;}

long long power(long long base, long long expo) {
    long long res = 1;
    while (expo > 0) {
        if (expo & 1) res = res * base;
        base = base * base;
        expo >>= 1;
        if (res > 1000000000 or (expo and base > 1000000000)) return -1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        if (n % 2) {
            cout << -1 << nl;
            continue;
        }
        int N = n;
        vector<int> factors = {1};
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) factors.push_back(i);
        }
        factors.push_back(N);
        // cout << factors.size() << nl;
        int a = -1, b;
        for (int i = 0; i < factors.size(); i++) {
            // cout << factors[i] << ' ';
            for (int j = 0; j < factors.size(); j++) {
                ll A = power(factors[i], factors[j]);
                if (A == -1) continue;
                A *= factors[j];
                ll B = power(factors[j], factors[i]);
                if (B == -1) continue;
                B *= factors[i];
                if (A > 1e9 or B > 1e9) continue;
                if (A + B == n) a = factors[i], b = factors[j];
            }
        }
        // cout << nl;
        if (a != -1) {
            cout << a << ' ' << b << nl;
        }
        else cout << a << nl;
    }
}