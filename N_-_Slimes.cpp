/*
    author:Karan
    created:04.12.2022 23:42:44
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
    vector<int> arr(n);
    vector<vector<bool>> used()
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    ll answer = 0;
    while(s.size() > 1) {
        ll a = *s.begin();
        s.erase(s.find(*s.begin()));
        ll b = *s.begin();
        s.erase(s.find(*s.begin()));
        answer += a+b;
        s.insert(a+b);
    }
    cout<<answer<<endl;
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