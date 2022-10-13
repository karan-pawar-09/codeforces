/*
    author:Karan
    created:16.08.2022 20:26:41
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
    ll n,q;
    cin>>n>>q;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    ll maxi = 0;
    vector<ll> total(n, 0);
    for(ll i=1;i<n;i++) {
        if(arr[i] > arr[maxi]) {
            total[i]++;
            maxi = i;
        } else {
            total[maxi]++;
        }
    }
    while(q--) {
        ll a,b;
        cin>>a>>b;
        ll starttime = max(a-1,1LL);
        if(b<starttime) {
            cout<<0<<endl;
        } else {
            if((a-1)!= maxi) {
                cout<<min((b-(max(a-1,1LL))+1), total[a-1])<<endl;
            } else {
                cout<<b-(max(a-1,1LL))+1<<endl;
            }
        }
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

// 1 2 6 5 4 7 3

// 1 -> 0

// 2 -> 1

// 6 -> 3

// 7 -> inf

