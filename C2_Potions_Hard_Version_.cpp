/*
author:Karan
created:09.08.2021 15:24:41
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
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    ll sum=0;
    ll ans=0;
    multiset<ll> negs;
    for(ll i=0;i<n;i++) {
        if(arr[i]>=0) {
            sum+=arr[i];
            ans++;
        }
        else {
            if(sum+arr[i]>=0) {
                negs.insert(arr[i]);
                sum+=arr[i];
                ans++;
            }
            else {
                ll diff=0;
                if(arr[i]> (*negs.begin()) ) {
                    diff=arr[i]- (*negs.begin());
                    negs.erase(negs.begin());
                    negs.insert(arr[i]);
                }
                sum+=diff;
            }
        }
    }
    cout<<ans<<endl;
} 