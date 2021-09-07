/*
author:Karan
created:02.09.2021 20:12:25
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    ll n,k;
    cin>>n>>k;
    vector< pair<ll,ll>> arr(n);
 
    for(int i=0; i<n; i++){
        cin>>arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end(), greater<>());

    vector<ll>ar(n);

    for(int i=0;i<k/2;i++){
        ll p = arr[i].second;
        ll ele = arr[i].first;
        ar[p] = ele;
    }
    ll p = arr[k/2].second;
    ll ele = arr[k/2].first;
    ar[p] = ele;
    for(int i=(k/2)+1; i<k; i++){
        ll p = arr[i].second;
        ll ele = arr[i].first;
        ar[p] = ele;
    }
    
    cout<<arr[k/2].first<<endl;

    for(int i=0; i<n; i++){
        if(ar[i]!=0)
        cout<<ar[i]<<" ";
    }

    cout<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        solve();
    }
}