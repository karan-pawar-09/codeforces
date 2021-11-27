/*
    author:Karan
    created:25.11.2021 20:06:03
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
    s=to_string(n);
    bool can=false;
    for(auto x:s) {
        if((x-'0')%2==0) {
            can=true;
            break;
        }
    }
    if((s[s.size()-1]-'0')%2==0) {
        cout<<0<<endl;
    }
    else if((s[0]-'0')%2==0) {
        cout<<1<<endl;
    }
    else if(can) {
        cout<<2<<endl;
    }
    else cout<<-1<<endl;
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