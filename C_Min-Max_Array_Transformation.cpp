/*
    author:Karan
    created:27.08.2022 21:05:43
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

ll binarysearch(ll a, vector<ll> & arr) {
    ll l = -1;
    ll r = arr.size()-1;
    while((l+1) < r) {
        ll m = (l+r)/2;
        if(arr[m]>=a) {
            r = m;
        } else l = m;
    }
    return arr[r];
}

ll binarysearch1(ll a, vector<ll> & arr) {
    ll l = 0;
    ll r = arr.size();
    while((l+1) < r) {
        ll m = (l+r)/2;
        if(arr[m] <= a) {
            l = m;
        } else r = m;
    }
    return arr[l];
}

void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n), b(n);
    for(ll i=0;i<n;i++) {
        cin>>a[i];
    }
    for(ll i=0;i<n;i++) {
        cin>>b[i];
    }
    for(ll i=0;i<n;i++) {
        cout<< binarysearch(a[i], b) - a[i] << " ";
    }
    cout<<endl;
    vector<ll> ans;
    ll maxi = n-1;
    for(ll i=n-1; i>=0; i--) { 
        ans.push_back(b[maxi]-a[i]);
        if(i!=0) {
            if(a[i] <= b[i-1]) {
                maxi = max(i, maxi);
            } else {
                maxi = i-1;
            }
        }   
    }
    reverse(all(ans));
    for(auto x: ans) {
        cout<<x<<" ";
    }
    cout<<endl;
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