/*
    author:Karan
    created:23.02.2022 16:34:50
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
    vector<int> arr(n);
    set<int> s;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        s.insert(arr[i]);
    }
    for(int i=1;i<=n;i++) {
        if(i<=s.size()) {
            cout<<s.size()<<" ";
        } else {
            cout<<i<<" ";
        }
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