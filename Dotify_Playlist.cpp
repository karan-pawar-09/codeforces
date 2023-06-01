/*
    author:Karan
    created:31.05.2023 20:03:41
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
    ll n, k, l;
    cin >> n >> k >> l;
    vector<pair<ll, ll>> arr(n);
    vector<ll> ar;
    for(ll i=0;i<n;i++) {
        cin >> arr[i].first;
        cin >> arr[i].second;
        if(arr[i].second == l) {
            ar.push_back(arr[i].first);
        }
    }
    sort(all(ar), greater<ll>());
    if(ar.size() < k) {
        cout<<-1<<endl;
        return;
    }
    ll sum = 0;
    for(ll i=0;i<k;i++) {
        sum += ar[i];
    }
    cout<<sum<<endl;
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