/*
    author:Karan
    created:21.11.2021 21:04:44
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
    ll one=0;
    ll two=0;
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        if(arr[i]%3==1) {
            one++;
        }
        else if(arr[i]%3==2) {
            two++;
        }
    }
    if(one==two) {
        cout<<one<<endl;
    } else {
        ll k=min(one,two);
        one-=k;
        two-=k;
        ll p=max(one,two);
        if(p%3==0) {
            cout<<k+((p/3)*2)<<endl;
        }
        else
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