/*
    author:Karan
    created:03.06.2023 21:26:23
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
    cin >> n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin >> arr[i];
    }
    if(arr.back()==1) {
        cout<<"NO"<<endl;
        return;
    }
    vector<ll> req;
    for(ll i=n-2;i >= 0;i--) {
        if(arr[i] != arr[i+1]) {
            req.push_back(i+1);
        }   
    }
    while(req.size() < n) {
        req.push_back(0);
    }
    sort(all(req));
    for(ll i=0;i<n;i++) {
        if(req[i] != 0) {
            if(req[i] > i) {
                cout<<"NO"<<endl;
                return;
            } 
        }
    }
    cout<<"YES"<<endl;
    for(auto x: req) {
        cout<<x<<" ";
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
