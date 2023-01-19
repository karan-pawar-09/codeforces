/*
    author:Karan
    created:18.01.2023 20:06:58
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
    int n;
    cin>>n;
    vector<pair<pair<int, int>, int>> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i].first.first;
        arr[i].second = i+1;
    }
    for(int i=0;i<n;i++) {
        cin>>arr[i].first.second;
    }
    sort(all(arr));
    cout<<arr[n-1].second<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}