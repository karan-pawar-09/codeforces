/*
    author:Karan
    created:18.06.2023 21:03:36
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

ll pw[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

void solve() {
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    if(c > (max(a, b) + 1)) {
        cout<<-1<<endl;
        return;
    }
    for(ll i = pw[a-1]; i < pw[a]; i++) {
        ll startb = pw[b-1];
        startb = max(startb, pw[c-1] - i);
        ll endb = min(pw[b] - 1, pw[c] - 1 - i);
        if(endb < startb) continue;
        if(k > (endb - startb + 1)) {
            k -= (endb - startb + 1);
        } else {
            cout<<i<<" + "<<startb + k - 1 <<" = "<<i + startb + k - 1<< endl;
            return;
        }
    }
    cout<<-1<<endl;
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

