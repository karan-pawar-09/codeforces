/*
    author:Karan
    created:04.03.2022 21:23:03
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
    sort(all(arr));
    ll l=1;
    ll r=n-1;
    ll sumblue=arr[0]+arr[1];
    ll sumred=arr[n-1];
    while(l<r) {
        if(sumred>sumblue) {
            if((l+1)>(n-r)) {
                cout<<"YES"<<endl;
                return;
            } else {
                l++;
                sumblue+=arr[l];
            }
        } else {
            r--;
            sumred+=arr[r];
        }
    }
    cout<<"NO"<<endl;
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