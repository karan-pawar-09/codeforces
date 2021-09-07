/*
author:Karan
created:05.06.2021 20:40:24
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(), ar.end()
#define endl '\n'

vector<ll> maxi;
vector<ll> lds;
vector<ll> lis;

ll lbs(vector<ll> arr, ll n) {
    ll i, j;
    lds.resize(n);
    lis.resize(n);
    for (i = 0; i < n; i++) {
        lis[i] = 1;
        maxi[i]=arr[i];
    }      
 
   
   for (i = 1; i < n; i++)
      for (j = 0; j < i; j++) {
         if (arr[i] < arr[j] && lis[i] <lis[j] + 1) {
             lis[i] = lis[j] + 1;
             maxi[i]=max(maxi[i],maxi[j]);
         }
         else if(arr[i] < arr[j] && lis[i] ==lis[j] + 1) {
             maxi[i]=maxi[j];
         }
      }   

    
    for (i = 0; i < n; i++)
      lds[i] = 1;

   for (i = n-2; i >= 0; i--)
      for (j = n-1; j > i; j--) {
         if (arr[i] < arr[j] && lds[i] < lds[j] + 1) {
             lds[i] = lds[j] + 1;
             maxi[i]=max(maxi[i],maxi[j]);
         }
         else if(arr[i] < arr[j] && lis[i] ==lis[j] + 1) {
             maxi[i]=maxi[j];
         }
      }     

    ll max = lis[0] + lds[0] - 1;
    for (i = 1; i < n; i++)
        if (lis[i] + lds[i] - 1 > max) {
            max = lis[i] + lds[i] - 1;
        }
    return max;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll n;
    cin >> n;
    maxi.resize(n, 0);
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ll k=lbs(arr, n);
    cout<<k<<endl;
    ll answer=0;
    for(int i=0;i<n;i++) {
        
        if(lds[i]+lis[i]-1==k) {
            cout<<maxi[i]<<" "<<arr[i]<<endl;
            answer=max(answer,maxi[i]-arr[i]);
        }
    }  
    cout <<answer<< endl;
}