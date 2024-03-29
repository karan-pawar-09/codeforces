/*
    author:Karan
    created:11.02.2022 21:45:51
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
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    map<int,int> M;
    for(auto x:arr) {
        M[x]++;
    }
    vector<int> ans;
    for(auto x:M) {
        if(x.second>=2) {
            ans.push_back(x.first);
        }
    }
    return ans;
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