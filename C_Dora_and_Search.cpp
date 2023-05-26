/*
    author:Karan
    created:12.02.2023 15:15:04
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
    multiset<ll> s1;
    multiset<ll, greater<ll>> s2;
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        s2.insert(arr[i]);
        s1.insert(arr[i]);
    }
    ll l = 0;
    ll r = n-1;
    while(l<r) {
        bool temp = false;
        if(s1.size() && *s1.begin() == arr[l] || *s2.begin() == arr[l]) {
            s1.erase(s1.find(arr[l]));
            s2.erase(s2.find(arr[l]));
            temp = true;
            l++;
        }
        if(s1.size() && *s1.begin() == arr[r] || *s2.begin() == arr[r]) {
            s1.erase(s1.find(arr[r]));
            s2.erase(s2.find(arr[r]));
            temp = true;
            r--;
        }
        if(!temp) {
            cout<<l+1<<" "<<r+1<<endl;
            return;
        }
        
    }
    cout<<-1<<endl;
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