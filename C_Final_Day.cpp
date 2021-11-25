/*
    author:Karan
    created:20.11.2021 17:50:15
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
    ll k,n;
    cin>>n>>k;
    vector<ll> score(n);
    vector<ll> ar(n);
    ll a,b,c;
    for(ll i=0;i<n;i++) {
        cin>>a>>b>>c;
        score[i]=a+b+c;
        ar[i]=score[i];
    }
    sort(all(ar),greater<ll>());
    ll kth=ar[k-1];
    for(ll i=0;i<n;i++) {
        if(score[i]+300>=kth) {
            cout<<"Yes"<<endl;
        }
        else {
            cout<<"No"<<endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}