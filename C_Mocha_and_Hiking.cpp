/*
author:Karan
created:15.08.2021 20:55:06
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
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        vector<ll> arr(n);
        bool zero=false;
        bool one=false;
        for(ll i=0;i<n;i++) {
            cin>>arr[i];
            if(arr[i]==0) {
                zero=true;
            }
            if(arr[i]==1) {
                one=true;
            }
        }
      
        {
            if(arr[0]==1) {
                cout<<n+1<<" ";
                for(ll i=0;i<n;i++) {
                    cout<<i+1<<" ";
                }
                cout<<endl;
            }
            else if(arr[n-1]==0) {
                
                for(ll i=0;i<=n;i++) {
                    cout<<i+1<<" ";
                }
                cout<<endl;
            }
            else {
                bool found=false;
                ll breakpt=-1;
                for(ll i=0;i<n-1;i++) {
                    if(arr[i]==0&&arr[i+1]==1) {
                        breakpt=i;
                        found=true;
                        break;
                    }
                }
                if(found) {
                    for(ll i=0;i<=breakpt;i++) {
                        cout<<i+1<<" ";
                    }
                    cout<<n+1<<" ";
                    for(ll i=breakpt+1;i<n;i++) {
                        cout<<i+1<<" ";
                    }
                    cout<<endl;
                }
                else {
                    cout<<-1<<endl;
                }
            }
        }
    }
}