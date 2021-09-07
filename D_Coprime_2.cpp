/*
author:Karan
created:21.08.2021 17:47:06
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const ll MAXN=1e5+7;

ll spf[MAXN];
 
void sieve() {
    spf[1] = 1;
    for (ll i=2; i<MAXN; i++)
        spf[i] = i;  
    for (ll i=4; i<MAXN; i+=2)
        spf[i] = 2;
    for (ll i=3; i*i<MAXN; i++) {        
        if (spf[i] == i) {            
            for (ll j=i*i; j<MAXN; j+=i)                  
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

set<ll> primes;

void getFactorization(ll x) {
    vector<ll> ret;
    while (x != 1) {
        primes.insert(spf[x]);
        x = x / spf[x];
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    sieve();
    ll n,m;
    cin>>n>>m;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
  
    for(ll i=0;i<n;i++) {
        getFactorization(arr[i]);
    }
    ll mx=(ll)1e5+7;
    vector<bool> is_prime(mx+1, true);
    is_prime[0] = is_prime[1] = false;
    for(auto x:primes) {
        is_prime[x]=false;
        for(ll j=2*x;j<mx;j+=x) {
            is_prime[j]=false;
        }
    }
    vector<ll> ans;
    ans.push_back(1);
    for(ll i=2;i<=m;i++) {
        if(is_prime[i]) {
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<endl;
    for(ll i=0;i<ans.size();i++) {
        cout<<ans[i]<<endl;
    }
}