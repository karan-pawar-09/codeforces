#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<pair<ll,ll>> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i].first>>arr[i].second;
    }
    ll m;
    cin>>m;
    vector<pair<ll,ll>>operation(m);
    for(ll i=0;i<m;i++) {
        cin>>operation[i].first;
        if(operation[i].first==3||operation[i].first==4) {
            cin>>operation[i].second;
        }
    }
    vector<<pair<ll,ll>> ans(m+1,vector<pair<ll,ll>>(n));
    for(ll i=1;i<=m;i++) {
        if(operation[i-1].first==1) {

                ans[i].first=ans[i-1].second;
                ans[i].second=-ans[i-1].first;
            
        }
        else if(operation[i-1].first==2) {
             
                ans[i][j].first=-ans[i-1][j].second;
                ans[i][j].second=ans[i-1][j].first;
            
        }
        else if(operation[i-1].first==3) {
           
                ll k=operation[i-1].second;
                ll l=ans[i-1][j].first;
                ans[i][j].first=2*(k-l)+ans[i-1][j].first;
                ans[i][j].second=ans[i-1][j].second;
           
        }
        else {
           
                ans[i][j].second=2*(operation[i-1].second-ans[i-1][j].second)+ans[i-1][j].second;
                ans[i][j].first=ans[i-1][j].first;
          
        }
    }

    ll q;
    cin>>q;
    for(ll i=0;i<q;i++) {
        ll a,b;
        cin>>a>>b;
        cout<<ans[a][b-1].first<<" "<<ans[a][b-1].second<<endl;
    }
}