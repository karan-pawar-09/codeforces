/*
    author:Karan
    created:16.01.2022 21:07:49
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

int sum(int n) {
    return (n*(n-1))/2;
}
void solve() {
    int n;
    cin>>n;
    int prev=0;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i].first;
    } 
    for(int i=0;i<n;i++) {
        cin>>arr[i].second;
    }
    for(int i=0;i<n;i++) {
        if(arr[i].second<=arr[i].first-prev) {
            ans+=sun(arr[i].second);
        } else {
            int p=arr[i-1].
        }
    }
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