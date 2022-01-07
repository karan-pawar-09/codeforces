/*
    author:Karan
    created:27.12.2021 20:58:05
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
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    string s;
    cin>>s;
    vector<ll> M(n+1);
    vector<ll> a,b;
    for(ll i=0;i<n;i++) {
        if(s[i]=='0') {
            a.push_back(arr[i]);
        } else {
            b.push_back(arr[i]);
        }
    }
    sort(all(a));
    sort(all(b));
    for(ll i=1;i<a.size()+1;i++) {
        M[a[i-1]]=i;
    }
    for(ll i=a.size()+1;i<=n;i++) {
        M[b[i-a.size()-1]]=i;
    }
    for(auto x:arr) {
        cout<<M[x]<<" ";
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