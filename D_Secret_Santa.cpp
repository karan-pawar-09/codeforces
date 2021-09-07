#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
template <typename T>
T myMax(T x, T y)
{
   return (x > y)? x: y;
}
void solve() {
    ll n;
        cin>>n;
        vector<ll> arr(n);
        map<ll,ll> Mapp;
        for(ll ith=0;ith<n;ith++) {
            cin>>arr[ith];
            if(Mapp.find(arr[ith])==Mapp.end()&&arr[ith]!=(ith+1)) {
                Mapp[arr[ith]]=ith;
            }
        }
        vector<ll> finall(n,-1);
        set<ll> val;
        for(ll ith=1;ith<=n;ith++) {
            val.insert(ith);
        }      
        for(auto x:Mapp) {
            finall[x.second]=x.first;
            val.erase(x.first);
        }
        for(ll ith=0;ith<n;ith++) {
            if(finall[ith]==-1) {
                for(ll x:val) {
                    if(x!=ith+1) {
                        finall[ith]=x;
                        val.erase(x);
                        break;
                    }
                }
            }
        }
        cout<<Mapp.size()<<endl;
        bool answer=true;
        for(ll ith=0;ith<n;ith++) {
            if(finall[ith]==-1) {
                answer=false;
                break;
            }
        }
        if(!answer) {
            Mapp.clear();
            for(ll ith=n-1;ith>=0;ith--) {               
                if(Mapp.find(arr[ith])==Mapp.end()&&arr[ith]!=(ith+1)) {
                    Mapp[arr[ith]]=ith;
                }
            }
            for(ll ith=0;ith<n;ith++) {                
                 all[ith]=-1;                
            }
            set<ll> val;
            for(ll ith=1;ith<=n;ith++) {
                val.insert(ith);
            }
            for(auto x:Mapp) {
                finall[x.second]=x.first;
                val.erase(x.first);
            }
            for(ll ith=0;ith<n;ith++) {
                if(finall[ith]==-1) {
                    if(finall[ith]==-1) {
                        for(ll x:val) {
                            if(x!=ith+1) {
                                finall[ith]=x;
                                val.erase(x);
                                break;
                            }
                        }
                    }
                }
            }
        }
        for(ll ith=0;ith<n;ith++) {
            cout<<finall[ith]<<" ";
        }
        cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--) {
        solve();
    }
} 