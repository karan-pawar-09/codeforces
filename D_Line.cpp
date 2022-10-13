/*
    author:Karan
    created:30.08.2022 21:02:18
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
    string s;
    cin>>s;
    ll ans = 0;
    for(ll i=0;i<n;i++) {
        if(s[i] == 'L') {
            ans += i;
        } else {
            ans += (n-1)-i;
        }
    }
    priority_queue<ll> pq;
    for(ll i=0;i<(n/2);i++) {
        ll temp1 = 0;
        ll temp2 = 0;
        ll j = n-i-1;
        if(s[i]=='L') {
            pq.push((n-i-1)-i);
        } 
        if(s[n-1-i] == 'R') {
            pq.push((n-1-i)-i);   
        }
       
    }
    for(ll i=0;i<n;i++) {
        if(pq.size()) {
            ans += pq.top();
            pq.pop();
        }
        cout<<ans<<" ";
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


// ---K----