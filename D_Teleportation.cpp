/*
    author:Karan
    created:07.11.2021 18:00:42
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
    vector<pair<ll,ll>> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i].first>>arr[i].second;
    }
    set<pair<ll,ll>> s;
    for(ll i=0;i<n;i++) {
        for(ll j=0;j<n;j++) {
            if(i!=j) {
                pair<ll,ll> p={arr[i].first-arr[j].first,arr[i].second-arr[j].second};
                ll a=p.first;
                ll b=p.second;
                p.first=abs(p.first);
                p.second=abs(p.second);
                while(__gcd(p.first,p.second)>1) {
                    ll k=__gcd(p.first,p.second);
                    p.first/=k;
                    p.second/=k;
                }
                if(a<0 ) {
                    p.first=-p.first;
                }
                if(b<0) {
                    p.second=-p.second;
                }
                if(s.find(p)==s.end()) {
                    s.insert(p);
                }
                else {
                    
                }
            }
        }
    }
    cout<<s.size()<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}