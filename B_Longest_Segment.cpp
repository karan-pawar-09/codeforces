/*
    author:Karan
    created:08.01.2022 17:35:41
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

long double dist(pair<int,int> &a, pair<int,int> &b) {
    return (long double) sqrt(((a.first-b.first)*(a.first-b.first))+((a.second-b.second)*(a.second-b.second)));
}
void solve() {
    int n;
    cin>>n;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i].first>>arr[i].second;
    }
    long double ans=0;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            ans=max(ans,dist(arr[i],arr[j]));
        }
    }
    cout<<fixed;
    cout<<setprecision(10);
    cout<<ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}