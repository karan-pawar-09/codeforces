/*
    author:Karan
    created:15.12.2022 13:40:48
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
    
    ll mini = 1e18+7;
    ll maxi = -1e18-7;
    ll minicount = 0;
    ll maxicount = 0;

    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] <= mini) {
            if(arr[i] < mini) {
                minicount = 1;
                mini = arr[i];
            } else {
                minicount++;
            }
        }
        if(arr[i] >= maxi) {
            if(arr[i] > maxi) {
                maxi = arr[i];
                maxicount = 1;
            } else {
                maxicount++;
            }
        }
    }

    if(maxi == mini) {
        cout<< n*(n-1)<<endl;
    } else {
        cout<<minicount*maxicount*2<<endl;
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