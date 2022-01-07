/*
    author:Karan
    created:29.12.2021 22:25:49
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
    int res=0;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int ans=1e9+7;
    for(int i=0;i<=200;i++) {
        int temp=0;
        for(int j=1;j<n-1;j++) {
            if(arr[i+1]-arr[i-1]==(2*i)) {
                temp++;
            } else {
                temp+=2;
            }
        }
        ans=min(ans,temp);
    }
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