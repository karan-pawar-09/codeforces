/*
    author:Karan
    created:25.03.2022 23:34:37
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
ll A, B, C, D;
map<char, ll> M;
string arr[] = { "ABCD", "ABDC", "ACBD", "ACDB", "ADBC", "ADCB", "BACD", "BADC", "BCAD", "BCDA",
            "BDAC", "BDCA", "CABD", "CADB", "CBAD", "CBDA", "CDAB", "CDBA", "DABC", "DACB", "DBAC", "DBCA", "DCAB",
            "DCBA" };
ll x, y;

bool calc(string s) {
    ll add = M[s[0]];
    ll mul = M[s[1]];
    ll sub = M[s[2]];
    ll div = M[s[3]];
    // cout << add << " " << mul << " " << sub << " " << div << endl;

    ll  a = (add + sub) / 2;
    ll  b = (add - sub) / 2;
    // cout << a << " " << b << endl;
    if (a >= 1 and a <= 10000 and b >= 1 and b <= 10000 and mul == a * b and (div == a / b)) {
        x = a;
        y = b;
        return true;
    }
    return false;

}
bool ans;
void k() {
    for (string x : arr) {
        ans |= calc(x);
    }
}
void solve() {
    cin >> A >> B >> C >> D;
    x = -1;
    y = -1;
    M.clear();
    M['A'] = A;
    M['B'] = B;
    M['C'] = C;
    M['D'] = D;
    k();
    cout << x << " " << y << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}