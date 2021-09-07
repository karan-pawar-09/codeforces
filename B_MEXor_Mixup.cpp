/*
author:Karan
created:05.09.2021 20:11:31
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int computeXOR(int n) {
  if (n % 4 == 0)
    return n;
  if (n % 4 == 1)
    return 1;
  if (n % 4 == 2)
    return n + 1;
  return 0;
}

void solve() {
    ll a,b;
    cin>>a>>b;
    ll xorr=computeXOR(a-1);    
    int ans=a+1;
    if(xorr==b) {
        ans--;
    }
    xorr^=b;
    
    if(xorr==a) {
        ans++;
    }
    cout<<ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        solve();
    }
}