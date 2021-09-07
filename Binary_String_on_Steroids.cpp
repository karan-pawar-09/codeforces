/*
author:Karan
created:20.06.2021 22:45:30
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

vector<ll> factors(ll n) {
    vector<ll> ans;
    for(ll i=1;i*i<=n;i++) {
        if(n%i==0) {
            if(i==n/i) {
                ans.push_back(i);
            }
            else {
                ans.push_back(i);
                ans.push_back(n/i);
            }
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        ll one=0;
        ll zero=0;
        string s;
        cin>>s;
        for(ll i=0;i<n;i++){
            s[i]=='1'?one++:zero++;
        }        
        vector<ll> factor=factors(n);
        ll ans=(ll)1e18+7;      
        {
            for(ll i=0;i<factor.size();i++) {
                ll a=factor[i];
                vector<ll> index(a);
                for(ll i=0;i<a;i++){
                    for(ll j=i;j<n;j+=a){
                        if(s[j]=='1') {
                            index[i]++;
                        }
                    }
                }
                for(int i=0;i<a;i++) {
                    ll pp=one+n/a-2*index[i];
                    ans=min(ans,pp);
                }
            }
            cout<<ans<<endl;
        }
    }
    
}