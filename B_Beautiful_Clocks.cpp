#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n' 
  
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<unsigned ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
   
    unsigned ll lcm=1;
    for(ll i=0;i<n;i++) {
        lcm=lcm/__gcd(lcm,arr[i])*arr[i];
    }
    cout<<lcm<<endl;
}