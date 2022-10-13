/*
    author:Karan
    created:19.08.2022 17:45:32
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

int ceil(int a, int b) {
    return (a+b-1)/b;
}
void solve() {
    int n, l;
    cin>>n>>l;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    arr.push_back(0);
    arr.push_back(l);
    sort(arr.begin(), arr.end());
    int maxi =0;
    for(int i=2;i<arr.size()-1;i++) {
        maxi = max(maxi, arr[i]-arr[i-1]);
    }
    int a= arr[1];
    int b= l-arr[n-2];
    cout<<max({a, b, ceil(maxi, 2)})<<endl;
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