/*
    author:Karan
    created:05.02.2022 17:36:02
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
    vector<int> arr(n+2);
    arr[0]=0;
    arr[n+1]=360;
    int prev=0;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        arr[i]=(arr[i]+prev)%360;
        prev=arr[i]%360;
    }
    sort(all(arr));
    int res=0;
    for(int i=1;i<arr.size();i++) {
        res=max(res,arr[i]-arr[i-1]);
    }
    cout<<res<<endl;
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