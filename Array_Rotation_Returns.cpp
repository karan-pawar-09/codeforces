/*
author:Karan
created:31.07.2021 19:16:49
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        vector<ll> a(n),b(n);
        for(ll i=0;i<n;i++) {
            cin>>a[i];
        }
        for(ll i=0;i<n;i++) {
            cin>>b[i];
        }
        ll mini=1e9+7;
        for(ll i=0;i<n;i++) {
            mini=min(mini,(a[0]+b[i])%n);
        }
        
        vector<ll> shift;
        for(ll i=0;i<n;i++) {
            if((a[0]+b[i])%n==mini) {
                shift.push_back(i);
            }
        }       
        if(shift.size()) {
            ll sizee=shift.size();
            vector<vector<ll>> seq(sizee,vector<ll> (n));
            for(ll i=0;i<sizee;i++) {
                ll k=shift[i];
                for(ll j=0;j<n;j++) {
                    seq[i][j]=(a[j]+b[(j+k)%n])%n;
                }
            }
            // sort(all(seq),comparator);
            for(ll i=0;i<seq.size();i++) {
                for(ll j=i+1;j<seq.size();j++) {
                    if(!lexicographical_compare(seq[i].begin(),seq[i].end(),seq[j].begin(),seq[j].end())) {
                        seq[i].swap(seq[j]);
                    }
                }
            }
            for(ll i=0;i<n;i++) {
                cout<<seq[0][i]<<" ";
            }
        }        
        cout<<endl;
    } 
}