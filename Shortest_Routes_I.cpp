/*
authot:Karan
created:20.05.2021 19:32:53
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const ll inf =(ll)1e17;
const ll mx =(ll)1e5+7;

ll n,m;

vector<pair<ll,ll>> arr[mx];
ll d[mx];

void dijsktras(ll a) {
    d[a]=0;
    set<pair<ll,ll>> s;
    s.insert({0,a});
    while(s.size()) {
        ll node=s.begin()->second;
        s.erase(s.begin());
        for(auto x:arr[node]) {
            ll dist=x.second;
            if(d[x.first]>dist+d[node]) {
                s.erase({d[x.first],x.first});
                d[x.first]=dist+d[node];
                s.insert({dist+d[node],x.first});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    cin>>n>>m;
    for(ll i=0;i<=n;i++) {
        d[i]=inf;
        arr[i].clear();
    }
    for(ll i=0;i<m;i++) {
        ll a,b,c;
        cin>>a>>b>>c;
        arr[a].push_back({b,c});
    }
    dijsktras(1);
    for(ll i=1;i<=n;i++) {
        cout<<d[i]<<" ";
    }
    cout<<endl;
}