/*
    author:Karan
    created:28.11.2021 20:52:18
*/
#if true
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
#define mset(a,x) memset(a,x,sizeof(a))
#endif

const ll mx=(ll)2e6+7;
vector<bool> is_prime;

void solve() {
    ll n,e;
    cin>>n>>e;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    ll ans=0;
    for(ll i=0;i<n;i++) {
        if(is_prime[arr[i]]) {
            ll left=0;
            ll right=0;
            for(ll j=i-e;j>=0;j-=e) {
                if(arr[j]==1) {
                    left++;
                }
                else {
                    break;
                }                
            }
            for(ll j=i+e;j<n;j+=e) {
                if(arr[j]==1) {
                    right++;
                } else break;
            }
            if(left>0 or right>0) {
                ans+=((left+1)*(right+1))-1;
            }
        }
    }
    cout<<ans<<endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    is_prime.resize(mx+1,true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= mx; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= mx; j += i)
                is_prime[j] = false;
        }
    }
    ll t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}