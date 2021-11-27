/*
    author:Karan
    created:27.11.2021 20:18:08
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
    int n;   cin>>n;
    vector<int> arr(2*n);
    for(int i=0;i<(2*n);i++) {
        cin>>arr[i];
    }
    set<int> s(all(arr));
    sort(all(arr));
    vector<int> v(all(s)),a;
    int i=0;
    for(int i=0;i<v.size();i++) {
        a.push_back(v[i/2]);
        a.push_back(v[(n-1+i)/2]);
    }
    
    sort(all(a));
    if(a.size()!=arr.size()) {
        cout<<-1<<endl;   return;
    }
    
    for(int i=0;i<a.size();i++) {
        if(a[i]!=arr[i]) {
            cout<<-1<<endl;   return;
        }
    } 
    for(auto i:s) {
        cout<<i<<" ";
    }
    cout<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}