/*
    author:Karan
    created:21.01.2023 20:06:55
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
    for(int i =0; i<n;i++) {
        cin>>arr[i];
    }
    int res = 1;
    int ans = 0;
    for(int i=0;i<n;i++) {
        if(i > 0 && (arr[i]%2 == arr[i-1]%2)) {
            res++;
        } else {
            ans += (res-1);
            res = 1;
        }
    }
    ans += res-1;
    cout<<ans<<endl;
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