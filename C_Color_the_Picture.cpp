/*
    author:Karan
    created:30.07.2022 14:44:14
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

bool check(ll n, ll m, vector<ll> & arr, ll k) {
    ll total = 0;
    bool odd = false;
    bool maxiodd = false;
    for(ll i = 0; i < k; i++) {
        if((arr[i] / n) >= 2) {
            total += arr[i] / n;
            if((arr[i] / n)>= 3) {
                if((arr[i]/n)%2) maxiodd =true;
                odd = true;
            }
        }
    }
    if(m % 2) {
        if(odd) {
            if(total >= m) {
                if(maxiodd) return true;
                else return total > m;
            }
            else return false;
        } else return false;
    } else {
        return total >= m;
    }
}
void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> arr(k);
    for(ll i = 0; i < k; i++) {
        cin >> arr[i];
    }
    (check(n, m, arr, k) || check(m, n, arr, k))? cout << "Yes" << endl : cout << "No" << endl;
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




// 2 3 5 3 2 1 7 4
// + - + - + - + -

// 2 3 5 3 2 1 7
// + - + - + - +