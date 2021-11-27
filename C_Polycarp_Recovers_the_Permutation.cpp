/*
    author:Karan
    created:25.11.2021 20:59:03
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
    bool k=true;
    for(ll i=0;i<n;i++) {
        if(i!=0 and i!=n-1 and arr[i]==n) {
            k=false;
            break;
        }
    }
    if(k) {
        for(ll i=((n-1)/2);i>=0;i--) {
            cout<<arr[i]<<" ";
        }
        for(ll i=n-1;i>((n-1)/2);i--) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    else cout<<-1<<endl;
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