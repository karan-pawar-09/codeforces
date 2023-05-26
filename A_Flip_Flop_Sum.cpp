/*
    author:Karan
    created:01.02.2023 20:06:38
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
    ll sum = 0;
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        sum += arr[i];
    }
    ll best = 0;
    ll better = 0;
    for(ll i=0;i<(n-1);i++) {
        if(arr[i]==-1 && arr[i+1]==-1) {
            best++;
        } else if(arr[i]==-1 || arr[i+1] == -1) {
            better++;
        } 
    }
    if(best) {
        cout<<sum+4<<endl;
    } else if(better) {
        cout<<sum<<endl;
    } else {
        cout<<sum-4<<endl;
    }
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