/*
    author:Karan
    created:01.09.2022 13:56:33
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

const ll inf = 1e18 + 18;

void solve() {
    bool arithmetic = true;
    bool geometric = true;
    bool fibonacchi = true;
    ll diff = inf;
    ll ratio = inf;
    ll sum = 1;
    ll prev = 0;
    ll cur = 1;
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
   
    if(n >= 2) {
        diff = arr[1]-arr[0];
        if(arr[0] != 0 && (arr[1]%arr[0] == 0)) {
            ratio = arr[1]/arr[0];
        } else {
            geometric = false;
        }
        if((arr[0] == 1) && (arr[1] == 1)) {
            prev = 1;
            cur = 1;
        } else {
            fibonacchi = false;
        }
    }
    for(ll i=2;i<n;i++) {
        if((arr[i]-arr[i-1]) != diff) {
            arithmetic = false;
        }
    }
    for(ll i = 2; i<n;i++) {
        if((arr[i-1]) != 0 && (arr[1]%arr[0] == 0)) {
            if((arr[i]/arr[i-1]) != ratio) {
                geometric = false;
            }
        } else {
            geometric = false;
        }
    }
    for(ll i=2;i<n;i++) {
        if((prev + cur) != arr[i]) {
            fibonacchi = false;
            break;
        } else {
            prev = cur;
            cur = arr[i];
        }
    }
    
    ll ans1 = inf;
    ll ans2 = inf;
    ll ans3 = inf;
    if(arithmetic) {
        ans1 = arr[n-1] + diff;
    } 
    if(geometric) {
        ans2 = arr[n-1] * ratio;
    }
    if(fibonacchi) {
        ans3 = prev + cur;
    }
    
    if(arithmetic) {
        cout<<arr[n-1]+diff;
    } else if(geometric) {
        cout<<arr[n-1]*ratio;
    } else if(fibonacchi) {
        cout<<prev+cur<<endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}