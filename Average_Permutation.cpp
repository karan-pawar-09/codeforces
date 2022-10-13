/*
    author:Karan
    created:03.08.2022 20:06:33
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
    if(n == 3) {
        cout<<"1 2 3"<<endl;
    } else {
        vector<int> arr(n+1);
        arr[n] = n;
        arr[1] = n-1;
        arr[2] = n-2;
        arr[n-1] = n-3;
        for(int i = 3; i< n-1; i++) {
            arr[i]=i-2;
        }
        for(int i=1;i<=n;i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
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