/*
    author:Karan
    created:23.08.2022 17:50:21
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

bool comp(pair<int, int> &a, pair<int, int> &b) {
    if((a.first*b.second) > (a.second*b.first)) {
        return true;
    } else if((a.first*b.second) < (a.second*b.first)) {
        return false;
    } else {
        return a.second < b.second;
    }
}
void solve() {
    int n;
    cin>>n;
    vector<int> arr(n+1);
    vector<pair<int, int>> ar(n);
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        ar[i-1].first = arr[i];
        ar[i-1].second = i;
    }
    sort(all(ar), comp);
    int t;
    cin>>t;
    int ans = 0;
    for(int i=0;i<n;i++) {
        if(t>0) {
            int time = t/(ar[i].second);
            ans += ar[i].first * time;
            t -= ar[i].second*time;
        } else {
            break;
        }
    }
    cout<<ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}