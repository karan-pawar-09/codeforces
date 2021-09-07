/*
author:Karan
created:18.08.2021 15:34:03
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const ll inf=1e18+7;

void solve() {
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> hospital(n+1,inf);
    vector<pair<ll,ll>> hos;
    for(ll i=0;i<k;i++) {
        ll a,b;
        cin>>a>>b;
        hospital[a]=b;
        hos.push_back({b,a});
    }
    sort(all(hos));
    vector<ll> ans(n+1,inf);
    ans[hos[0].second]=hos[0].first;
    vector<vector<pair<ll,ll>>> arr(n+1);
    for(ll i=0;i<m;i++) {
        ll a,b,c;
        cin>>a>>b>>c;
        arr[a].push_back({b,c});
        arr[b].push_back({a,c});
    }
    using pii = pair<ll, ll>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({hos[0].first,hos[0].second});
    while(q.size()) {
        ll v=q.top().second;
        ll d=q.top().first;
        q.pop();
        if(d!=ans[v]) continue;
        for(auto edge:arr[v]) {
            ll to=edge.first;
            ll len=edge.second;
            if(ans[v]+len<ans[to]) {
                ans[to]=ans[v]+len;
                q.push({ans[to],to});
            }
            if(hospital[to]<ans[to]) {
                ans[to]=hospital[to];
                q.push({ans[to],to});
            }
        }
    }
    for(ll i=1;i<=n;i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        solve();
    }
}