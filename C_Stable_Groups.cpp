/*
author:Karan
created:20.06.2021 16:15:29
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll n,k,x;
    cin>>n>>k>>x;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    } 
    sort(all(arr));
    vector<pair<ll,ll>> ans;
    ans.push_back({arr[0],arr[0]});
    for(ll i=1;i<n;i++) {
        if(arr[i]-arr[i-1]<=x) {
            ans.back().second=arr[i];
        }
        else {
            ans.push_back({arr[i],arr[i]});
        }
    }
    ll answer=ans.size();
    vector<ll> total;
    for(ll i=1;i<ans.size()&&k>0;i++) {
        ll diff= ans[i].first-ans[i-1].second;
        ll add=(diff+x-1)/x;
        add--;
        total.push_back(add);
    }
    sort(all(total));
    for(ll i=0;i<total.size()&&k>0;i++) {
        if(k<total[i]) {
            break;
        }
        {
            k-=total[i];
            answer--;
        }
    }
    cout<<answer<<endl;
}