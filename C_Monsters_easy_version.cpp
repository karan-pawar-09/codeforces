/*
    author:Karan
    created:05.02.2023 18:14:25
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
        cin>>arr[i];
    }
    sort(all(arr));
    ll cur = 1;
    ll temp = 0;
    for(ll i=0;i<n;i++) {
        //cout<<arr[i]<<" "<<cur<<endl;
        if(arr[i] < cur) {

        } else {
            if(arr[i] == cur) {
                cur++;
            } else {
                temp += arr[i]-cur;
                cur++;
            }
            
        }
    }
    cout<<temp<<endl;
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