#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

bool sortbysec1(const pair<ll,pair<ll,ll>> &a, const pair<ll,pair<ll,ll>> &b) {
    return (a.second.second < b.second.second);
}
bool sortbysec2(const pair<ll,pair<ll,ll>> &a, const pair<ll,pair<ll,ll>> &b) {
    return (a.second.first < b.second.first);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--) {
        ll n,k,w;
        cin>>n>>k>>w;
        vector<pair<ll,pair<ll,ll>>> arr;
        for(ll i=0;i<n;i++) {
            ll a,b;
            cin>>a>>b;
            arr.push_back({i,{a,b}});            
        }
        sort(all(arr),sortbysec1);
        sort(all(arr),sortbysec2);
        ll tm=0;
        tm=arr[0].second.first+arr[0].second.second;       
        arr[0].second.first=k*arr[0].second.second;
        for(ll i=1;i<n;i++) {
            arr[i].second.first=arr[i].second.second*k-max(0LL,tm-arr[i].second.first)*w;
            tm+=arr[i].second.second;
        }
        sort(all(arr));
        for(ll i=0;i<n;i++) {
            cout<<arr[i].second.first<<" ";
        }
    }
}