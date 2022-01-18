/*
    author:Karan
    created:09.01.2022 17:19:46
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

int MinCost(int N, vector<int> A) {
    vector<int> freq(1e6+10,0);
    for(int i=0;i<N;i++) {
        freq[A[i]]++;
    }
    int ans=0;
    for(int i=0;i< (1e6+10);i++) {
        ans+=freq[i]%2;
    }
    return ans;
}

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<MinCost(n,arr)<<endl;
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