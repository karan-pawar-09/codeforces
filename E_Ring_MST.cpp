/*
author:Karan
created:17.07.2021 17:59:47
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
    ll n,m;
    cin>>n>>m;
    map<ll,ll> M;
    pair<ll,ll> odd={(ll)1e18+7,-1};
    pair<ll,ll> even={(ll)1e18+7,-1};
    for(ll i=0;i<m;i++) {
        ll p,q;
        cin>>p>>q;  
        if(M.find(q)==M.end()) {
            M[p]=q;
        }
        else {
            M[p]=min(M[p],q);
        }      
    }
    m=M.size();
    vector<pair<ll,ll>> arr(m);
    ll zz=0;
    for(auto x:M) {
        arr[zz].first=x.second;
        arr[zz].second=x.first;
        zz++;
    }    
    sort(all(arr));
    pair<ll,ll> one;
    pair<ll,ll> two;
    if(n%arr[0].second!=0||arr[0].second==1) {
        cout<<arr[0].first*(n-1)<<endl;
    }   
    else {
        bool find=false;
        for(ll i=0;i<m;i++) {
            for(ll j=i+1;j<m;j++) {
                if(n%(arr[i].second+arr[j].second)!=0) {
                    one={arr[i].first,arr[i].second};
                    two={arr[j].first,arr[j].second};
                    find=true;
                    break;
                }
            }
            if(find==true) break;
        }
        if(find==false) {
            cout<<-1<<endl;
        }
        else {
            cout<<one.first*(n-2)+two.first<<endl;
        }
    }

}