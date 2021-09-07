#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
 
ll No = 1e6;
ll MOD = 1e9 + 7;
vector<ll> fact;

void factorial() {
   fact[0] = 1 ;
   for(ll i = 1; i< No; i++)
       fact[i] = i * fact[i-1] % MOD ;
}

ll Ex(ll a, ll pow) {
   a%= MOD;
   ll res=1;
   while(pow> 0) {
       if(pow&1) res = res * a % MOD;
       a = a * a % MOD;
       pow >>= 1;
   }
   return res;
}
ll Inv(ll a) {
   return Ex(a,MOD-2) % MOD ;
}
 
int main() {
    fact.resize(No);
   factorial();
   int t; cin>>t;
   while(t--) {
       ll x,y,z; cin>>x>>y>>z;
       ll n = x+y+z;
       ll num=(fact[2*n])%MOD;
       ll den= ((fact[x]%MOD*fact[y]%MOD*fact[z]%MOD*fact[n+1]%MOD)%MOD)%MOD;
       ll ans = (num%MOD*Inv(den)%MOD)%MOD;
       if(n==0) ans=0;
       cout <<ans<< endl;
   }
}
