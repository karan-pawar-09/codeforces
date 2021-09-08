/*
    author:Karan
    created:08.09.2021 20:35:36
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
const ll mx=1e5+7;
const ll mod=998244353;
ll fact[mx];
ll ifact[mx];

ll mul(ll a,ll b) {
    return (a*b)%mod;
}
ll sub(ll a,ll b) {
    return (a-b+mod+mod)%mod;
}
ll power(long long x, unsigned ll y, ll mod) {
    ll res = 1; 
    x = x % mod;   
    if (x == 0) return 0;  
    while (y > 0) {        
        if (y & 1)
            res = (res*x) % mod; 
        y = y>>1;
        x = (x*x) % mod;
    }
    return res;
}
ll modInv(ll a,ll mod) {
    return power(a,mod-2,mod) % mod ;
}
ll ncr(ll n,ll r) {
    return mul(mul(fact[n],ifact[r]),ifact[n-1]);
}
void solve() {
    ll n;
    cin>>n;
    ll no=n;
    ll ans=fact[n];
    vector<ll> arr(n);
    map<ll,ll> M;
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        M[arr[i]]++;
    }
    sort(all(arr));
    ll ind=0;
    ll prev;
    bool answer=true;
    for(auto x:M) {
        if(ind>0) {
            if(x.first-prev>1) {
                answer=false;
                break;
            }
        }
        prev=x.first;
        ind++;
    }
    ll maxi=arr[n-1];
    if(!answer) {
        cout<<0<<endl;
    }
    else {
        ind=0;
        
        vector<ll> num;
        for(auto x:M) {
            num.push_back(x.second);
        }
        if(num[0]>1) {
            cout<<ans<<endl;
        }
        else {
            n=num.size();
            reverse(all(num));
            ll sum=0;
            ll temp=fact[num[0]];
            for(ll i=1;i<n;i++) {
                sum+=num[i];
                if(i==1) {                                           
                    ll ss=(mul(mul(temp,fact[sum]),fact[no-sum-num[0]]));  
                    ans=sub(ans,ss);
                }
                else {                      
                    ll ss=mul(mul(mul(temp,fact[sum]),fact[no-sum-num[0]]), (no-sum-num[0]+num[i]));   
                    ans=sub(ans,ss);

                }
                
            }
            cout<<ans<<endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    fact[1]=1;
    fact[0]=1;
    ifact[1]=1;
    for(ll i=2;i<mx;i++) {
        fact[i]=mul(fact[i-1],i);
        ifact[i]=modInv(fact[i],mod);
    }
    ll t;
    cin>>t;
    while(t--) {
        solve();
    }
}