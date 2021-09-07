/*
author:Karan
created:29.08.2021 20:20:11
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
        vector<ll> zeros,ones;
        ll odd=0;
        ll even=0;
        for(ll i=0;i<n;i++) {
            cin>>arr[i];
            if(arr[i]%2) {
                arr[i]=1;
                ones.push_back(i);
                odd++;
            } else {
                arr[i]=0;
                zeros.push_back(i);
                even++;
            }
        }
        if(abs(even-odd)>1) {
            cout<<-1<<endl;
        }
        else {
              if(odd>even) {
                  vector<ll> ans(n);
                  for(ll i=0;i<n;i++) {
                      if(i%2==0) {
                          ans[i]=1;
                      }
                      else {
                          ans[i]=0;
                      }
                  }
                  vector<ll> z;
                  for(ll i=0;i<n;i++) {
                      if(ans[i]==0) {
                          z.push_back(i);
                      }
                  }
                  ll sum=0;
                  for(ll i=0;i<z.size();i++) {
                      sum+=abs(z[i]-zeros[i]);
                  }
                  cout<<sum<<endl;
              }
              else if(odd<even) {
                  vector<ll> ans(n);
                  for(ll i=0;i<n;i++) {
                      if(i%2==0) {
                          ans[i]=0;
                      }
                      else {
                          ans[i]=1;
                      }
                  }
                  vector<ll> o;
                  for(ll i=0;i<n;i++) {
                      if(ans[i]==1) {
                          o.push_back(i);
                      }
                  }
                  ll sum=0;
                  for(ll i=0;i<o.size();i++) {
                      sum+=abs(o[i]-ones[i]);
                  }
                  cout<<sum<<endl;
              }
              else {
                  vector<ll> a(n),b(n);
                  for(ll i=0;i<n;i++) {
                      if(i%2==0) {
                          a[i]=0;
                          b[i]=1;
                      }
                      else {
                          a[i]=1;
                          b[i]=0;
                      }
                  }
                  vector<ll> o,z;
                  for(ll i=0;i<n;i++) {
                      if(a[i]==0) {
                          z.push_back(i);
                      }
                      else {
                          o.push_back(i);
                      }
                  }
                  ll sum1=0;
                  ll sum2=0;
                  for(ll i=0;i<o.size();i++) {
                      sum1+=abs(zeros[i]-z[i]);
                      sum2+=abs(zeros[i]-o[i]);
                  }
                  cout<<min(sum1,sum2)<<endl;
              }          
        }
    }
}