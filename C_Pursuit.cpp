#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
void solve() {
ll n;
        cin>>n;
        vector<ll> ara(n+1),arb(n+1);
        vector<ll> sumone(n+1,0),sumtwo(n+1,0);
        ll sum1=0,sum2=0;
        for(ll i=1;i<=n;i++) {
            cin>>ara[i];
        }

        for(ll i=1;i<=n;i++) {
            cin>>arb[i];
        }
        sort(all(ara));
        sort(all(arb));
        for(ll i=1;i<=n;i++) {
            if(i==1) {
                sumtwo[i]=arb[i];
                sumone[i]=ara[i];
            }
            else {
                sumtwo[i]=sumtwo[i-1]+arb[i];
                sumone[i]=sumone[i-1]+ara[i];
            }
        }
        ll l=-1;
        ll r=1e14+7;
        while(l+1<r) {
            ll m=l+(r-l)/2;
            ll k=n+m;
            ll low=k/4;
            ll sum=0;
            if(low<=n) {
                sum=sumone[n]-sumone[low];
            }
            sum+=100*(m);
            ll s2=0;
            ll no=k-low;
            s2=sumtwo[n]-sumtwo[max(0LL,(ll)(n-no))];
            if(sum>=s2) {
                r=m;
            }
            else {
                l=m;
            }
        }
        cout<<r<<endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--) {
        solve();
    }
}