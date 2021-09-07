/*
author:Karan
created:15.06.2021 15:16:41
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
    ll n;
    cin>>n;
    vector<ll> arr(n);
    ll sum=0;
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        sum+=arr[i];
    }   
    if(sum%3) {
        cout<<0<<endl;
        return 0;
    }
    else {
        ll a=0;
        ll ans=0;
        ll ss=0;
        for(ll i=0;i<n-1;i++) {
            ss+=arr[i];
            if(ss==(2*sum)/3) {
                ans+=a;
            }
            if(ss==sum/3) {
                a++;
            }
            
        }
        cout<<ans<<endl;
    }
}