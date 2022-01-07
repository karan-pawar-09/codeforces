/*
    author:Karan
    created:03.01.2022 20:17:52
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
    vector<pair<pair<ll,ll>,ll>> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i].first.first>>arr[i].first.second>>arr[i].second;
    }
    ll mini=1e18+8;
    ll maxi=-(1e18+8);
    map<ll,ll> Mx,Mn;
    map<pair<ll,ll>,ll> single;
    for(ll i=0;i<n;i++) {
        if(Mx.find(arr[i].first.second)!=Mx.end())
            Mx[arr[i].first.second]=min(Mx[arr[i].first.second],arr[i].second);
        else Mx[arr[i].first.second]=arr[i].second;

        if(Mn.find(arr[i].first.first)!=Mn.end())
            Mn[arr[i].first.first]=min(Mn[arr[i].first.first],arr[i].second);
        else Mn[arr[i].first.first]=arr[i].second;

        if(single.find(arr[i].first)!= single.end()) {
            single[arr[i].first]=min(single[arr[i].first],arr[i].second);
        } else single[arr[i].first]=arr[i].second;

        if(arr[i].first.first<=mini) {
            mini=arr[i].first.first;
        } 
        if(arr[i].first.second>=maxi) {
            maxi=arr[i].first.second;            
        }
        ll k=Mn[mini]+Mx[maxi];
        if(single.find({mini,maxi})!=single.end()) {
            k=min(k,single[{mini,maxi}]);
        }
        cout<<k<<endl;
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