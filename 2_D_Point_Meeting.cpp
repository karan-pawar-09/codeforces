/*
    author:Karan
    created:10.09.2021 20:05:20
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const ll inf=1e18+7;
const pair<ll,ll> invalid={inf,inf};
pair<ll,ll> intersect(pair<ll,ll> P1,pair<ll,ll> P2,pair<ll,ll> par1,pair<ll,ll> par2) {
    if(par1==par2) return invalid;
    if(P1.first==0) {
        if(P2.first==1) {
            return {P1.second-P2.second,P1.second};
        }
        else if(P2.first==-1) {
            return {P2.second-P1.second,P1.second};
        }
        else {
            return {-P2.second,P1.second};
        }
    }
    else if(P1.first==1) {
        if(P2.first==0) {
            return {P2.second-P1.second,P2.second};
        }
        else if(P2.first==-1) {
            if((P2.second-P1.second)%2 or (P2.second+P1.second)%2) {
                return invalid;
            }
            return {(P2.second-P1.second)/2,(P2.second+P1.second)/2};
        }
        else {
            return {-P2.second,P1.second-P2.second};
        }
    }
    else if(P1.first==-1) {
        if(P2.first==0) {
            return {P1.second-P2.second,P2.second};
        }
        else if(P2.first==1) {
            if((P1.second-P2.second)%2 or (P2.second+P1.second)%2) {
                return invalid;
            }
            return {(P1.second-P2.second)/2,(P2.second+P1.second)/2};
        }
        else {
            return {-P2.second,P2.second+P1.second};
        }
    }
    else {
        if(P2.first==0) {
            return {-P1.second,P2.second};
        }
        else if(P2.first==1) {
            return {-P1.second,P2.second-P1.second};
        }
        else {
            return {-P1.second,P2.second+P1.second};
        }
    }
}
void solve() {
    ll n;
    cin>>n;
    vector<pair<ll,ll>> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i].first;
    }
    for(ll i=0;i<n;i++) {
        cin>>arr[i].second;
    }
    set<pair<ll,ll>> s;
    for(ll i=0;i<n;i++) {
        s.insert(arr[i]);
    }
    map<ll,ll> xaxis,yaxis;
    for(ll i=0;i<n;i++) {
        xaxis[arr[i].first]++;
    }
    vector<pair<ll,ll>> xa,ya;
    for(ll j=0;j<n;j++) {
        yaxis[arr[j].second]++;
    }
    for(auto x:xaxis) {
        xa.push_back({x.second,x.first});
    }
    for(auto x:yaxis) {
        ya.push_back({x.second,x.first});
    }
    sort(all(xa),greater<pair<ll,ll>>());
    sort(all(ya),greater<pair<ll,ll>>());

    ll maxix=xa[0].first;
    ll maxiy=ya[0].first;

    ll total=2*n;
    ll ans=2*n;
    for(ll i=0;i<xa.size() and xa[i].first==maxix ;i++) {
        for(ll j=0;j<ya.size() and ya[i].first==maxiy ;j++) {
            ll temp=0;
            if(s.find({xa[i].second,ya[i].second})!=s.end()) temp++;
            ans=min(ans,total-maxix-maxiy-temp);
        }
    }
    vector<pair<pair<ll,ll>,pair<int,int>>> lines;
    for(ll i=0;i<n;i++) {
        lines.push_back({{0,arr[i].second},arr[i]});
        lines.push_back({{1,arr[i].second-arr[i].first},arr[i]});
        lines.push_back({{-1,arr[i].second+arr[i].first},arr[i]});
        lines.push_back({{inf,-arr[i].first},arr[i]});
    }
    ll ans2=2*n;
    map<pair<double,double>,ll> M;
    for(ll i=0;i<lines.size();i++) {                
        for(ll j=i+1;j<lines.size();j++) {            
            if(true) {
                if(intersect(lines[i].first,lines[j].first,lines[i].second,lines[j].second)!=invalid){
                    M[intersect(lines[i].first,lines[j].first,lines[i].second,lines[j].second)]+=2;
                }
            }            
        }
    }
    
    for(ll i=0;i<n;i++) {
        for(ll j=i+1;j<n;j++) {
            if(arr[j].second-arr[i].second==(-arr[j].first+arr[i].first)) {
                M[arr[i]]+=2;
                M[arr[j]]+=2;
            }
        }
    }
    for(auto &x:M) {
        cout<<x.first.first<<" "<<x.first.second<<" -> "<<x.second<<endl;
        if(s.find(x.first)!=s.end()) {
            x.second++;
        }
    }
    for(auto x:M) {
        ans2=min(ans2,total-x.second);
    }
    cout<<min(ans,ans2)<<endl;
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