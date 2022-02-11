
/*
    author:Karan
    created:31.01.2022 20:29:32
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


ll ceil(ll a , ll b) {
	return (a+b-1)/b;
}
void solve() {
    ll hc,dc,hm,dm;
    cin>>hc>>dc;
    cin>>hm>>dm;
    ll k,w,a;
    cin>>k>>w>>a;
    bool ans=false;
    for(ll i=0;i<=k;i=i+1) {
        ll Hc=hc+(i*a);
        ll Dc=dc+((k-i)*w);
		ll a=ceil(Hc,dm);
		ll b=ceil(hm,Dc);
        if(a>=b) {
            ans=true;
            break;
        }
    }
    if(ans) {
        cout<<"YES"<<endl;
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




