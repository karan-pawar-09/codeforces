/*
author:Karan
created:24.05.2021 20:19:03
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++) {
            cin>>arr[i];
        }
        sort(all(arr));
        if(arr.back()<=0) {
            cout<<n<<endl;
        }
        else {
            set<ll> answer;
            for(ll i=0;i<n;i++) {
                if(arr[i]<=0) {
                    answer.insert(arr[i]);
                }
            }
            ll temp1=0;
            for(ll i=0;i<n;i++) {
                if(arr[i]>0) {
                    break;
                }
                else {
                    temp1++;
                }
            }
            vector<ll> ar;
            for(ll x:answer) {
                ar.push_back(x);
            }
            ll diff=(ll)1e18+7;
            // for(ll i=0;i<ar.size()-1;i++) {
            //     if(ar.size()>1) {
            //         if(ar[i+1]-ar[i]<diff) {
            //             diff=arr[i+1]-ar[i];
            //         }
            //     }
            // }
            if(ar.size()>1) {
                for(int i=1;i<ar.size();i++) {
                    if(ar[i]-ar[i-1]<diff) {
                        diff=ar[i]-ar[i-1];
                    }
                }
            }
            bool isthere=false;
            for(ll i=0;i<n;i++) {
                if(arr[i]>0&&arr[i]<=diff) {
                    isthere=true;
                    break;
                }
            }
            ll temp2=answer.size()+isthere;
            cout<<max(temp1,temp2)<<endl;
        }
    }
}