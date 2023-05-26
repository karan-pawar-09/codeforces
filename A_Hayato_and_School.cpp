/*
    author:Karan
    created:25.01.2023 20:09:53
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
    vector<ll> s1, s2;
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        if(arr[i]%2) {
            s1.push_back(i);
        } else {
            s2.push_back(i);
        }
    }
    if(s1.size() >= 3) {
        cout<<"YES"<<endl;
        for(ll i=0;i<3;i++) {
            cout<<s1[i]+1<<" ";
        }
        cout<<endl;
    } else if(s1.size() >= 1 && s2.size() >= 2) {
        cout<<"YES"<<endl;
        cout<<s1[0]+1<<" ";
        cout<<s2[0]+1<<" ";
        cout<<s2[1]+1<<" ";
        cout<<endl;
    } else {
        cout<<"NO"<<endl;
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