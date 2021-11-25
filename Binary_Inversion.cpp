/*
    author:Karan
    created:17.11.2021 20:17:14
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
    vector<pair<ll,string>> inversions(n);
    vector<string> arr(n);
    string s;
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        inversions[i].second=arr[i];
    }
    for(ll i=0;i<n;i++) {
        ll zero=0;
        ll inv=0;
        for(ll j=m-1;j>=0;j--) {
            if(arr[i][j]=='0') {
                zero++;
            }
            else {
                inv+=zero;
            }
        }
        inversions[i].first=zero;
    }
    sort(all(inversions));
    ll zero=0;
    ll inv=0;
    for(ll i=0;i<n;i++) {
        for(ll j=m-1;j>=0;j--) {
            if(inversions[i].second[j]=='0') {
                zero++;
            }
            else {
                inv+=zero;
            }
        }
    }
    cout<<inv<<endl;
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