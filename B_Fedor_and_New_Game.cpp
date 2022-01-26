/*
    author:Karan
    created:20.01.2022 23:01:40
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
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> arr(m);
    for(int i=0;i<m;i++) {
        cin>>arr[i];
    }
    int x;
    cin>>x;
    int res=0;
    for(int i=0;i<m;i++) {
        int diff=0;
        for(int j=0;j<32;j++) {
            if((arr[i]&(1<<j))^(x&(1<<j))) {
                diff++;
            }
        }
        if(diff<=k) {
            res++;
        }
    }
    cout<<res<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}