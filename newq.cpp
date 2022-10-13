/*
    author:Karan
    created:28.09.2022 17:28:35
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
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> arr(n, vector<ll> (m));
    for(ll i=0;i<n;i++) {
        for(ll j=0;j<m;j++) {
            cin>>arr[i][j];
            if(i==0) {
                if(j==0) {

                } else {
                    arr[i][j] = arr[i][j-1] + arr[i][j]; 
                }
            } 
            else if(j == 0) {
                if(i==0) {

                } else {
                    arr[i][j] = arr[i-1][j] + arr[i][j];
                }
            } else {
                arr[i][j] = arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1] + arr[i][j];
            }
        }
    }
    for(ll i=0;i<n;i++) {
        for(ll j=0;j<m;j++) {
            cout<<arr[i][j]<<" ";
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
    //cin>>t;
    while(t--) {
        solve();
    }
}