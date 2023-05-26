/*
    author:Karan
    created:29.01.2023 20:25:07
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

ll primeFactors(ll n) {
    ll xx = n;
    map<ll, ll> M;
    ll ans = 0;
    while (n % 2 == 0) {
        M[2]++;
        n = n/2;
    }

    for (ll i = 3; i <= sqrt(xx); i = i + 2) {
        while (n % i == 0) {   
            M[i]++;
            n = n/i;
        }
    }

    if (n > 2) {
        M[n]++;
    }
   
    ll sum = 0;
    while(M.size()) {
        ll temp = 1;
        bool used = false;
        for(auto &x: M) {
            if(x.second) {
                used = true;
                temp *= x.first;
                x.second--;
            }
        }
        if(used == false) {
            break;
        }
        sum += temp;
    }
    return sum;
}

void solve() {
    ll n;
    cin>>n;
    cout<<primeFactors(n)<<endl;
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