/*
    author:Karan
    created:11.09.2021 17:41:54
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    ll n;
    cin>>n;
    set<pair<ll,ll>> points;
    vector<pair<ll,ll>> pts;
    vector<ll> x(n),y(n);
    for(ll i=0;i<n;i++) {
        pair<ll,ll> p;
        cin>>p.first>>p.second;
        pts.push_back(p);
        points.insert(p);
    }
    ll answer=0;
    for(ll i=0;i<n;i++) {
        for(ll j=i+1;j<n;j++) {
            pair<ll,ll> p1=pts[i];
            pair<ll,ll> p2=pts[j];
            if(p1.first == p2.first || p1.second == p2.second)
            continue;
            pair<ll, ll> p3 = make_pair(p1.first, p2.second);
            pair<ll, ll> p4 = make_pair(p2.first, p1.second);

            if(points.find(p3) != points.end() && points.find(p4) != points.end())
                ++answer;
            }
    }
    cout<<answer/2<<endl;
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