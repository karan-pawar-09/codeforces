/*
    author:Karan
    created:13.10.2022 20:20:58
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

const ll mx = 1e3+10;
bool arr[mx][mx];
void solve() {
    ll n;
    cin>>n;
    vector<ll> ar(n);
    vector<ll> pos(mx, -1);
    for(ll i=0;i<n;i++) {
        cin>>ar[i];
        pos[ar[i]] = i+1;
    }
    ll ans = -1;
    for(ll i=1;i<mx;i++) {
        for(ll j=1;j<mx;j++) {
            if(pos[i] != -1 && pos[j] != -1) {
                if(arr[i][j]) {
                    ans = max(ans, pos[i]+pos[j]);
                }
            }
        }
    }
    cout<<ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    cin>>t;
    for(ll i=1;i<mx;i++) {
        for(ll j=1;j<mx;j++) {
            arr[i][j] = false;
        }
    }
    for(ll i=1;i<mx;i++) {
        for(ll j=1;j<mx;j++) {
            if(__gcd(i, j)==1) {
                arr[i][j] = true;
            }
        }
    }
    while(t--) {
        solve();
    }
}