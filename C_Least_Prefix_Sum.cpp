/*
    author:Karan
    created:04.01.2023 00:28:10
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

ll calc1(vector<ll> arr) {
    ll sum = 0;
    ll p = 0;
    multiset<ll, greater<ll>> s;
    ll ret = 0;
    for(ll x: arr) {
        sum -= x;
        s.insert(x);
        while(sum < 0) {
            sum += 2 * (*s.begin());
            ret += 1;
            s.erase(s.begin());
        }
        
    }
    return ret;
}
ll calc2(vector<ll> arr) {
    long long sum = 0;
    multiset<ll> s;
    ll ret = 0;
    for (ll x : arr) {
        sum += x;
        s.insert(x);
        while (sum < 0) {
        sum -= 2 * (*s.begin());
        ret += 1;
        s.erase(s.begin());
        }
    }
    return ret;
}
void solve() {
    ll n, m;
    cin>>n>>m;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    vector<ll> a, b;
    for(ll i=1;i<m;i++) {
        a.push_back(arr[i]);
    }
    reverse(all(a));
    for(ll i=m;i<n;i++) {
        b.push_back(arr[i]);
    }
    cout<<calc1(a)<<" "<<calc2(b)<<endl;
    cout<<calc1(a)+calc2(b)<<endl;
    
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

