/*
author:Karan
created:16.06.2021 16:03:27
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
    }  
    vector<ll> a(5);
    for(ll i=0;i<5;i++) {
        cin>>a[i];
    }
    vector<ll> ans(5,0);
    for(ll i=0;i<n;i++){
        sum+=arr[i];
        for(ll j=4;j>=0;j--) {
            if(sum>=a[j]) {
                int ques=sum/a[j];
                ans[j]+=ques;
                sum%=a[j];
            }
        }
    }
    for(ll i=0;i<5;i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl<<sum<<endl;
}