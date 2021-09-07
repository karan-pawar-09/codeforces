/*
author:Karan
created:04.09.2021 21:23:08
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    ll l,q;
    cin>>l>>q;
    set<ll> arr;
    arr.insert(0);
    arr.insert(l);
    ll c,x;
    while(q--) {
        cin>>c>>x;
        if(c==2) {
            ll up=*arr.upper_bound(x);
            auto it=arr.lower_bound(x);
            it--;
            ll down=*it;
            cout<<up-down<<endl;
        }
        else {
            arr.insert(x);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}