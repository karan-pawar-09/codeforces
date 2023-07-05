/*
    author:Karan
    created:02.07.2023 12:16:28
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
    ll n;
    cin >> n;
    set<ll> numbers;
    map<ll, ll> M;
    multiset<ll> ans;
    while (n--) {
        ll a, b;
        cin >> a;
        if (a == 1) {
            cin >> b;
            M[b]++;
            if (numbers.count(b)) {
                ans.insert(0);
                continue;
            }
            auto it = numbers.upper_bound(b);
            if (it != numbers.end()) {
                ans.insert(b ^ (*it));
            }
            if (it != numbers.begin()) {
                ans.insert(b ^ (*prev(it)));
            }
            if (it != numbers.end() && it != numbers.begin()) {
                ans.erase(ans.find((*it) ^ (*prev(it))));
            }
            numbers.insert(b);
        }
        else if (a == 2) {
            cin >> b;
            M[b]--;
            if (M[b] != 0) {
                ans.erase(0);
                continue;
            }
            auto it = numbers.lower_bound(b);
            if (next(it) != numbers.end()) {
                ans.erase(ans.find((*it) ^ (*next(it))));
            }
            if (it != numbers.begin()) {
                ans.erase(ans.find((*it) ^ (*prev(it))));
            }
            if (next(it) != numbers.end() && it != numbers.begin()) {
                ans.insert((*prev(it)) ^ (*next(it)));
            }
            numbers.erase(b);
        }
        else {
            cout << *ans.begin() << endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t = 1;
    //cin>>t;
    while (t--) {
        solve();
    }
}