/*
    author:Karan
    created:05.02.2023 17:48:29
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

const ll mx = 1e6+10;
char player[mx];
ll alice[mx];
ll bob[mx];
void solve() {
    ll n;
    cin>>n;
    cout<<alice[n-1]<<" "<<bob[n-1]<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    cin>>t;
    ll len = 2;
    player[0] = 'A';
    ll cur = 1;
    ll count = 0;
    for(ll len = 2;len < mx;len++) {
        ll temp = len;
        if(count < 2) {
            while(temp--) {
                if(cur >= mx) {
                    break;
                }
                player[cur++] = 'B';
            }
            count++;
        } else {
            while(temp--) {
                if(cur >= mx) {
                    break;
                }
                player[cur++] = 'A';
            }
            count++;
            count %= 4;
        }
    }
    alice[0] = 1;
    bob[0] = 0;
    for(ll i=1;i<mx;i++) {
        if(player[i]=='A') {
            alice[i] = alice[i-1]+1;
            bob[i] = bob[i-1];
        } else {
            alice[i] = alice[i-1];
            bob[i] = bob[i-1] + 1;
        }
    }
    while(t--) {
        solve();
    }
}