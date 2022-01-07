/*
    author:Karan
    created:18.12.2021 10:12:57
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
    int n,m;
    cin>>n>>m;
    vector<int> arr(m);
    for(int i=0;i<m;i++) {
        cin>>arr[i];
    }
    int ans=0;
    int sum=0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<m;i++) {
        if(sum+arr[i]>n) {
            break;
        }
        else {
            sum+=arr[i];
            ans++;
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