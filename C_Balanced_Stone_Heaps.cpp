/*
    author:Karan
    created:02.01.2022 12:14:09
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

ll binarysearch(vector<ll> &arr) {
    ll n=arr.size();
    ll l=0;
    ll r=1e18+7;
    while(l+1<r) {
        ll m=l+(r-l)/2;
        vector<ll> ar=arr;
        bool ans=true;
        for(ll i=n-1;i>=2;i--) {
            if(ar[i]>=m) {
                ll diff=ar[i]-m;
                if(diff>arr[i]) {
                    diff=arr[i];
                }
                ll k=diff/3;
                ar[i-1]+=k;
                ar[i-2]+=(2*k);
            } else {
                ans=false;
                break;
            }
        }   
        for(ll i=0;i<2;i++) {
            if(ar[i]>=m) {

            }
            else {
                ans=false;
                break;
            }
        }    
        if(ans) {
            l=m;
        } else {
            r=m;
        }
    }
    return l;
}
void solve() {
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    ll k=binarysearch(arr);
    cout<<k<<endl;
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