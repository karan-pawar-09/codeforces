/*
author:Karan
created:22.06.2021 00:34:46
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

bool complete(vector<bool> &visited) {
    bool ans=true;
    for(ll i=0;i<visited.size();i++) {
        if(visited[i]==false) {
            ans=false;
            break;
        }
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll n;
    cin>>n;
    vector<pair<ll,ll>> arr(n);
    vector<bool> visited(n,false);
    for(ll i=0;i<n;i++) {
        cin>>arr[i].second>>arr[i].first;
    }
    sort(all(arr));
    ll ans=0;
    vector<ll> pts;
    for(ll i=0;i<n;i++) {
        if(complete(visited)) {
            break;
        }
        if(!visited[i]) {
            ans++;
            pts.push_back(arr[i].first);
            visited[i]=true;
            for(ll j=i+1;j<n;j++) {
                if(arr[j].second<=arr[i].first&&arr[j].first>=arr[i].first) {
                    visited[j]=true;
                }
            }
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<pts.size();i++) {
        cout<<pts[i]<<" ";
    }
    cout<<endl;
}
