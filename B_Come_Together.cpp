/*
    author:Karan
    created:29.06.2023 20:12:54
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
    vector<pair<ll, ll>> arr(3);
    for(ll i = 0LL; i < 3; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    ll answer = 1;
    if((arr[1].first < arr[0].first && arr[2].first < arr[0].first) || (arr[1].first > arr[0].first && arr[2].first > arr[0].first)) {
        answer += min(abs(arr[0].first - arr[1].first), abs(arr[0].first - arr[2].first));
    }
    if((arr[1].second < arr[0].second && arr[2].second < arr[0].second) || (arr[1].second > arr[0].second && arr[2].second > arr[0].second)) {
        answer += min(abs(arr[0].second - arr[1].second), abs(arr[0].second - arr[2].second));
    }
    cout<<answer<<endl;
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