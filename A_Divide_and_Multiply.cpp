/*
    author:Karan
    created:28.11.2021 20:09:41
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
    ll maxiodd=0;
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        if(arr[i]%2) {
            if(arr[i]>maxiodd) {
                maxiodd=arr[i];
            }
        }
    }
    sort(all(arr));
    ll res=1;
    ll sum=0;
    for(ll i=0;i<n;i++) {
        while(arr[i]%2==0) {
            res*=2;
            arr[i]/=2;
        }
        sum+=arr[i];
    }

    ll k=*max_element(all(arr));
    sum-=k;
    sum+=(k*res);    
    cout<<sum<<endl;
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