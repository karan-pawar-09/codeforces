/*
    author:Karan
    created:18.01.2023 20:17:54
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
    int count = 0;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        if(arr[i] == 1) {
            count++;
        }
    }
    if(count%2 == n%2) {
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