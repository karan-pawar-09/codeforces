/*
    author:Karan
    created:17.11.2021 22:54:08
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
    ll n,m;
    cin>>n>>m;
    vector<ll> A(n),B(m);
    ll a=0;
    ll b=0;
    for(ll i=0;i<n;i++) {
        cin>>A[i];
        a+=A[i];
    }
    for(ll i=0;i<m;i++) {
        cin>>B[i];
        b+=B[i];
    }
    ll dif=b-a;
    sort(all(A));
    sort(all(B),greater<ll>());
    vector<ll> diff;
    for(ll i=0;i<min(n,m);i++) {
        if(B[i]>A[i])
            diff.push_back(B[i]-A[i]);
    }
    sort(all(diff),greater<ll>());
    ll i=0;
    while(dif>=0 and i<diff.size()) {
        dif-=diff[i]*2;
        i++;
    }
    if(dif<0) {
        cout<<i<<endl;
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