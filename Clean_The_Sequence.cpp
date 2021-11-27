/*
    author:Karan
    created:26.11.2021 22:50:24
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
    ll n,k;
    cin>>n>>k;
    vector<ll> arr(k+1,0);
    vector<ll> ar(n);
    for(ll i=0;i<n;i++) cin>>ar[i];
    vector<int> final;
    int prev=ar[0];
    final.push_back(ar[0]);
    for(int i=1;i<n;i++) {
        if(prev!=ar[i]) {
            prev=ar[i];
            final.push_back(ar[i]);
        }
    }
    ll total=0;
    for(ll i=1;i<final.size();i++) {
        bool k=false;
        if(final[i]!=final[i-1]) {
            total++;
            arr[final[i]]++;
            arr[final[i-1]]++;
            k=true;
        }            
        if(i!=final.size()-1 and k) {
            if(final[i]!=final[i+1] and final[i-1]!=final[i+1]) {
                arr[final[i]]--;
            }
        }        
    }
    for(ll i=1;i<=k;i++) {
        cout<<max(0LL,total-arr[i])<<" ";
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