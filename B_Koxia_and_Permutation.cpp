/*
    author:Karan
    created:01.01.2023 10:46:11
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
    int n, k;
    cin>>n>>k;
    vector<int> arr(n);
    int p = n;
    for(int i=0;i<n;i+=2) {
        arr[i] = p;
        p--;
    }
    p = 1;
    for(int i=1;i<n;i+=2) {
        arr[i] = p;
        p++;
    }
    for(auto x: arr) {
        cout<<x<<" ";
    }
    cout<<endl;
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