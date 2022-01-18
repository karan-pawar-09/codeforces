/*
    author:Karan
    created:10.01.2022 20:09:17
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
    ll a,b,c;
    cin>>a>>b>>c;
    bool ans=false;

    ll diff=b-a;
    ll next=b+diff;
    if(next%c==0 and next>=c) {
        ans=true;
    }

    diff=c-b;
    ll prev=b-diff;
    if(prev%a==0 and prev>=a) {
        ans=true;
    }

    diff=c-a;
    if(diff%2==0) {
        ll middle=(c+a)/2;
        if(middle%b==0 and middle>=b) {
            ans=true;
        }
    }
    
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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