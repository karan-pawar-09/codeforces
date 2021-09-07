/*
author:Karan
created:27.07.2021 22:18:32
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

set<ll> s;
ll n;
vector<ll> arr;

void iterate(ll no,ll i,ll spec) {
    if(i>=n) {
        return;
    }
    if(i==spec) {
        iterate(no,i+1,spec);
    }
    else{
        s.insert(no+arr[i]);
        s.insert(no-arr[i]);
        s.insert(arr[i]-no);
        s.insert(no);
        iterate(no+arr[i],i+1,spec);
        iterate(no-arr[i],i+1,spec);
        iterate(no,i+1,spec);
    }
    
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        s.clear();
        cin>>n;
        arr.resize(n);
        for(ll i=0;i<n;i++) {
            cin>>arr[i];
        }
        bool ans=false;
        sort(all(arr));
        for(ll i=1;i<n;i++) {
            if(arr[i]==arr[i-1]) {
                ans=true;
            }
        }
        if(ans) {
            cout<<"YES"<<endl;
        }
        else {
            if(n==1&&arr[0]==0) {
                ans=true;
            }
            if(ans) {
                cout<<"YES"<<endl;
            }
            else {
                for(ll i=0;i<n;i++) {
                    s.clear();
                    iterate(0,0,i);
                    if(s.find(arr[i])!=s.end()) {
                        ans=true;
                    }
                }            
                ans?cout<<"YES"<<endl:cout<<"NO"<<endl;
            }
            
        }
        
    }
    
}