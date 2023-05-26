/*
    author:Karan
    created:19.02.2023 16:39:05
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
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int count = 0;
    for(int i=1;i<n;i++) {
        if((arr[i]-arr[i-1]) >= 120) {
            count++;
        }
    }
    if(arr[0] >= 120) {
        count++;
    }
    if(1400-arr[n-1] >= 120) {
        count++;
    }
    if(count>=2) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
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