/*
    author:Karan
    created:27.08.2022 21:37:48
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
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<n;i++) {
        cin>>b[i];
    }
    sort(all(a));
    sort(all(b), greater<ll>());
    vector<int> afreq(32, 0), bfreq(32, 0);
    for(int i=0;i<n;i++) {
        
    }
    int ans = 0;
    for(int j=0;j<32;j++) {
        int count = 0;
        for(int i=0;i<n;i++) {
            if(((1<<j)&a[i]) & ((1<<j)&b[i])) {
                count++;
            }
        }
        if(count == n) {
            ans+=(1<<j);
        }
    }
    // for(int i=0;i<32;i++) {
    //     for(int j=0;j<n;j++) {
    //         if((1<<i) & a[j]) {
    //             afreq[i]++;
    //         }
    //     }
    // }
    // for(int i=0;i<32;i++) {
    //     for(int j=0;j<n;j++) {
    //         if((1<<i) & b[j]) {
    //             bfreq[i]++;
    //         } 
    //     }
    // }
    // int ans = 0;
    // for(int i=31;i>=0;i--) {
    //     if((afreq[i]+bfreq[i]) >= n) {
    //         ans += (1<<i);
    //     }
    // }
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