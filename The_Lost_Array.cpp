/*
    author:Karan
    created:19.06.2022 22:56:11
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
    cin>>n;
    vector<ll> arr(n+1);
    ll mxor = 0;
    for(ll i = 0; i <= n; i++) {
        cin >> arr[i];
        mxor ^= arr[i];
    }
    sort(all(arr));
    if(n%2) {
        bool isonece =false;
        for(ll i = 0; i <= n; i++) {
            if(arr[i] != mxor) {
                ll temp = arr[i] ^ mxor;
                cout << temp << " ";
            } else {
                if(isonece) {
                    ll temp = arr[i] ^ mxor;
                    cout << temp << " ";
                } else {
                    isonece = true;
                }
            }
        }
        cout << endl;
    } 
    else {
        for(ll i = 1; i <= n; i++) {
            ll temp = arr[0]^arr[i];
            cout << temp << " ";
        }
        cout<<endl;
    }
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