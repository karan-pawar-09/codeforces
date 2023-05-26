/*
    author:Karan
    created:02.02.2023 14:20:18
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
    cin >> n;
    vector<int> arr(n);
    vector<int> pref(n);
    for(int i=0;i<n;i++) {
        if(i%2) {
            arr[i] = 0;
        } else {
            arr[i] = 1;
        }
        if(i==0) {
            pref[i] = arr[i];
        } else {
            pref[i] = pref[i-1] + arr[i];
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            int sum = pref[j];
            if(i-1 >= 0) {
                sum -= pref[i-1];
            }
            assert(sum%(j-i+1));
        }
    }
    for(auto x: arr) {
        cout<<x<<" ";
    }
    cout<<endl;
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