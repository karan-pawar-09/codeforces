/*
    author:Karan
    created:09.01.2022 15:10:25
*/
#if true
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define all(ar) ar.begin(),ar.end()
#define endl '\n'
#define mset(a,x) memset(a,x,sizeof(a))
#endif


#define ll long long
const ll mod=(ll)1e9+7;

ll binarysearch(ll x,vector<ll> &brain) {
    ll l=-1;
    ll r=brain.size()-1;
    while(l+1<r) {
        ll m=l+(r-l)/2;
        if(brain[m]>=x) {
            r=m;
        } else {
            l=m;
        }
    }
    return r;
}

ll add(ll a,ll b) {
    return ((a%mod)+(b%mod))%mod;
}
ll sub(ll a,ll b) {
    return ((a%mod)-(b%mod) +mod)%mod;
}
ll mul(ll a, ll b) {
    return ((a%mod)*(b%mod))%mod;
}

int beautyBrain(int N, string s) {
    int n=N;
    vector<ll> beauty,brain;
    for(ll i=0;i<n;i++) {
        if(s.substr(i,6)=="beauty") {
            beauty.push_back(i);
        }
        if(s.substr(i,5)=="brain") {
            brain.push_back(i+4);
        }
    }
    brain.push_back(1e18+7);
    ll ans=0;
    int prev=0;
    if(beauty.size()) {        
        for(ll i=0;i<beauty.size();i++) {
            ll k=binarysearch(beauty[i],brain);
            if(brain[k]==(1e18+7)) {
                break;
            }
            else {
                ll after=n-brain[k]-1;
                ll before=beauty[i];                
                ans=add(ans,mul(after+1,before+1));
                ans=sub(ans,mul(prev,after+1));
                prev+=before+1;
            } 
        }
        
    }
    return (int)ans;
}
void solve() {
    ll n;
    cin>>n;
    string s;    
    cin>>s;
    int ans=beautyBrain(n,s);
    cout<<ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}