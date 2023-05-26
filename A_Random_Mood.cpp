/*
    author:Karan
    created:22.02.2023 00:03:24
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

double calc(double p, int n) {
    double prob = 1.0;
    while(n > 0) {
        if(n%2) {
            prob = prob * (1 - p) + (1 - prob) * p;
        } 
        n = n/2;
        p = p * (1 - p) + (1 - p) * p;
    }
    return prob;
}

double rec(double p, int n) {
    if(n == 0) return 1.0;
    double k = rec(p, n/2);
    k = (1 - k) * (1 - k) + k * k;
    if(n % 2) {
        k = k * (1 - p) + (1 - k) * p;
    }
    return k;
}
void solve() {
    int n;
    double p;
    cin >> n;
    cin >> p;
    cout<<fixed;
    cout<<setprecision(10);
    //cout<<calc(p, n)<<endl;
    cout<<rec(p, n) << endl;
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