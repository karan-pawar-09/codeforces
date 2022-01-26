/*
    author:Karan
    created:25.01.2022 22:14:13
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

void solve() {
    ll n,m,k;
    cin>>n>>m>>k;
    for(ll i=0;i<=n;i++) {
        d[i]=inf;
        arr[i].clear();
    }
    for(ll i=0;i<m;i++) {
        ll a,b,c;
        cin>>a>>b>>c;
        arr[a].push_back({b,c});
    }
    dijsktras(k);
    ll res=0;
    for(ll i=1;i<=n;i++) {
        res=max(res,d[i]);
    }
    if(res==inf)cout<<-1<<endl;
    else cout<<res<<endl;
    cout<<endl;
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