
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
#define mset(a,x) memset(a,x,sizeof(a))

ll binarysearch(ll b,ll f, ll c) {
    ll l=0;
    ll r=1e9+7;
    while(l+1<r) {
        ll m=l+(r-l)/2;
        ll x=b*m*m;
        ll y=f;
        if((b*m) >= ((c)+(f/m))) {
            r=m;
        } else {
            l=m;
        }
    }
    return r;
}
void solve() {    
    ll b,f,c;
    cin>>b>>f>>c;
    if(b-f>=c) cout<<0<<endl;
    else
        cout<<binarysearch(b,f,c)<<endl;
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