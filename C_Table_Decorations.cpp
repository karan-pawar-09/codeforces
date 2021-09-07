/*
author:Karan
created:30.06.2021 11:15:26
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    vector<ll> arr(3);
    cin>>arr[0]>>arr[1]>>arr[2];
    sort(all(arr));
    ll ans=(arr[0]+arr[1]+arr[2])/3;
    ans=min(ans,arr[0]+arr[1]);
    cout<<ans<<endl;
}