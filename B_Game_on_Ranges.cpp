/*
    author:Karan
    created:31.12.2021 16:44:33
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
    vector<pair<ll,ll>> arr(n);
    vector<vector<bool>> isThere(n+1,vector<bool> (n+1,false));
    for(ll i=0;i<n;i++) {
        cin>>arr[i].first>>arr[i].second;
        isThere[arr[i].first][arr[i].second]=true;
    }
    for(int i=0;i<n;i++) {
        for(int j=arr[i].first;j<=arr[i].second;j++) {
            if((j==arr[i].first or isThere[arr[i].first][j-1]) and (j==arr[i].second or isThere[j+1][arr[i].second])) {
                cout<<arr[i].first<<" "<<arr[i].second<<" "<<j<<endl;
            }
        }
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