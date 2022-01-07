/*
    author:Karan
    created:29.12.2021 21:29:53
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
    int ans=0;
    map<int,int> M;
    for(int i=-100;i<=100;i++) {
        M[i]=0;
    }
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        if(M[arr[i]]==0) {
            ans++;
            M[arr[i]]++;
        } else {
            if(M[-arr[i]]==0) {
                ans++;
                M[-arr[i]]++;
            }
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
    cin>>t;
    while(t--) {
        solve();
    }
}