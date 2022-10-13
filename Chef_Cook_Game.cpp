/*
    author:Karan
    created:10.08.2022 22:17:02
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
    if(n==1) {
        cout<<"Cook"<<endl;
        return;
    }
    vector<int> pre(n);
    pre[0]=arr[0];
    for(int i=1;i<n;i++) {
        pre[i]=pre[i-1]+arr[i];
    }
    bool ans =false;
    if(pre[n-2]%2) {
        ans = true;
    }
    for(int i=1;i<n-1;i++) {
        if(pre[i]%2 && arr[i]==0) {
            ans = true;
        }
    }
    ans? cout<<"Chef"<<endl:cout<<"Cook"<<endl;
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