/*
author:Karan
created:02.07.2021 17:48:08
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
    ll n,m,kk;
    cin>>n>>m>>kk;
    set<pair<pair<ll,ll>,pair<ll,ll>>> s;
    vector<pair<ll,ll>> path;
    pair<ll,ll> first;
    bool one=false;
    ll k=0;
    ll t=0;
    for(ll i=0;i<n;i++) {
        if(i%2) {
            for(ll j=m-1;j>=0;j--) {
                if(k==kk-1) {
                    first={i,j};
                    one=true;
                    break;
                }
                if(t%2&&(k<kk-1)) {
                    s.insert({path.back(),{i,j}});
                    k++;
                }
                t++;
                path.push_back({i,j});
            }
        }
        else {
            for(ll j=0;j<m;j++) {
                if(k==kk-1) {
                    first={i,j};
                    one=true;
                    break;
                }
                if(t%2&&(k<kk-1)) {
                    s.insert({path.back(),{i,j}});
                    k++;
                }  
                t++;               
                path.push_back({i,j});
            }
        }
        if(one) break;
    }
    vector<pair<ll,ll>> last;
    bool first_time=true;
    for(ll i=first.first;i<n;i++) {
        if(i%2) {
            for(ll j=m-1;j>=0;j--) {
                if(i==first.first&&first_time) j=first.second,first_time=false;
                last.push_back({i,j});
            }
        }
        else {
            for(ll j=0;j<m;j++) {
                if(i==first.first&&first_time) j=first.second,first_time=false;
                last.push_back({i,j});
            }
        }
    }
    for(auto x:s) {
        cout<<2<<" "<<x.first.first+1<<" "<<x.first.second+1<<" "<<x.second.first+1<<" "<<x.second.second+1<<endl;
    }
    cout<<last.size()<<" ";
    for(ll i=0;i<last.size();i++) {
        cout<<last[i].first+1<<" "<<last[i].second+1<<" ";
    }
    cout<<endl;
}