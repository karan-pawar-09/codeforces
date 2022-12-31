/*
    author:Karan
    created:27.12.2022 15:56:25
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

ll ceil(ll a, ll b) {
    return (a+b-1)/b;
}
void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    ll mini , maxi;
    mini = 0;
    maxi = 1e9;

    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    
    for(ll i=0;i<n-1;i++) {
        ll cur = arr[i];
        ll next = arr[i+1];
        if(cur < next) {
            maxi = min(maxi, (cur+next)/2);
        } else if(cur > next) {
            mini = max(mini, ceil((cur+next), 2));
        }
    }

    if(maxi >= mini) {
        cout<<maxi<<endl;
    } else {
        cout<<-1<<endl;
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