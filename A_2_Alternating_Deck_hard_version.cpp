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
ll alicew[mx];
ll aliceb[mx];
ll bobw[mx];
ll bobb[mx];
void solve() {
    ll n;
    cin>>n;
    cout<<alicew[n-1]<<" "<<aliceb[n-1]<<" "<<bobw[n-1]<<" "<<bobb[n-1]<<endl;
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
    alicew[0] = 1;
    aliceb[0] = 0;
    bobw[0] = 0;
    bobb[0] = 0;
    for(ll i=1;i<mx;i++) {
        if(player[i]=='A') {
            if(i%2) {
                aliceb[i] = aliceb[i-1] + 1;
                alicew[i] = alicew[i-1];
                bobw[i] = bobw[i-1];
                bobb[i] = bobb[i-1];
            } else {
                alicew[i] = alicew[i-1] + 1;
                aliceb[i] = aliceb[i-1];
                bobw[i] = bobw[i-1];
                bobb[i] = bobb[i-1];
            }
        } else {
            if(i%2) {
                bobb[i] = bobb[i-1] + 1;
                bobw[i] = bobw[i-1];
                aliceb[i] = aliceb[i-1];
                alicew[i] = alicew[i-1];
            } else {
                bobw[i] = bobw[i-1] + 1;
                bobb[i] = bobb[i-1];
                aliceb[i] = aliceb[i-1];
                alicew[i] = alicew[i-1];
            }
        }
    }
    while(t--) {
        solve();
    }
}