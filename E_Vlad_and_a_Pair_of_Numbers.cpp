/*
    author:Karan
    created:27.01.2023 21:00:43
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
    cin >> n;
    ll sum = 0;
    vector<ll> arr;
    vector<bool> available(30, false);
    for(ll i=0;i<30;i++) {
        if(n&(1<<i)) {
            sum += (1<<i);
        } else {
            available[i] = true;
        }
    }
    
    ll k = n/2;
    bool ans = true;
    for(ll i=0;i<30;i++) {
        if(k&(1<<i)) {
            if(!available[i]) {
                cout<<-1<<endl;
                return;
            }
        }
    }
    
    if(n%2) {
        cout<<-1<<endl;
        return;
    }
    cout<<n+(n/2)<<" "<<n/2<<endl;
    

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
