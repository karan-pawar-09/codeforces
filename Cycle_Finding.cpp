/*
author:Karan
created:13.07.2021 00:16:07
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const ll inf=(ll)1e18+7;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,pair<ll,ll>>> arr(m);
    for(ll i=0;i<m;i++) {
        cin>>arr[i].first>>arr[i].second.first>>arr[i].second.second;
    }
    vector<ll> d(n+1,inf);
    vector<ll> p(n+1,-1);
    d[1]=0;
    ll x;
    for(ll i=0;i<n;i++) {
        x=-1;
        for(auto e:arr) {
            if(d[e.first]+e.second.second<d[e.second.first]) {
                d[e.second.first]=d[e.first]+e.second.second;
                p[e.second.first]=e.first;
                x=e.second.first;
            }
        }
    }
    if(x==-1) {
        cout<<"NO"<<endl;
    }
    else {
        cout<<"YES"<<endl;
        vector<ll> ans;
        for (ll i = 0; i < n; ++i)
            x = p[x];
        for(ll i=p[x];i!=x;i=p[i]) {
            ans.push_back(i);
        }
        ans.push_back(x);
        ans.push_back(ans.front());
        reverse(all(ans));
        for(auto x:ans) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}