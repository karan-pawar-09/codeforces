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
    // if(par1==par2) return invalid;
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
bool online(pair<ll,ll> a,pair<ll,ll> b) {
    if(a.second==b.second) return true;
    else if(a.first==b.first) return true;
    else if(b.second-a.second==b.first-a.first) return true;
    else if((b.second-a.second==a.first-b.first)) return true;
    return false;
}
bool linept(pair<ll,ll> a, pair<ll,ll> b) {
    if(a.first==inf) {
        b.second=0;
        a.first=1;
    }
    return (b.second==((a.first*b.first)+a.second));
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

    vector<pair<pair<ll,ll>,pair<ll,ll>>> lines;
    for(ll i=0;i<n;i++) {
        lines.push_back({{0,arr[i].second},arr[i]});
        lines.push_back({{1,arr[i].second-arr[i].first},arr[i]});
        lines.push_back({{-1,arr[i].second+arr[i].first},arr[i]});
        lines.push_back({{inf,-arr[i].first},arr[i]});
    }
    ll ans2=2*n;
    map<pair<ll,ll>,set<pair<ll,ll>>> M;
    for(ll i=0;i<lines.size();i++) {                
        for(ll j=i+1;j<lines.size();j++) {            
            if(true) {
                if(intersect(lines[i].first,lines[j].first,lines[i].second,lines[j].second)!=invalid and s.find(intersect(lines[i].first,lines[j].first,lines[i].second,lines[j].second))==s.end()){
                    M[intersect(lines[i].first,lines[j].first,lines[i].second,lines[j].second)].insert(lines[i].second);
                    M[intersect(lines[i].first,lines[j].first,lines[i].second,lines[j].second)].insert(lines[j].second);
                }
            }            
        }
    }
    ll third=0;
    for(ll i=0;i<n;i++) {
        ll temp=2;
        for(ll j=0;j<n;j++) {
            if(i!=j) {
                if(online(arr[i],arr[j])) {
                    temp++;
                }
            }
        }
        third=max(third,temp);
    }
    for(auto x:M) {
        ans2=min(ans2,(ll)(total-(x.second.size())));
    }
    
    map<pair<ll,ll>,set<pair<ll,ll>>> slope1;
    map<pair<ll,ll>,set<pair<ll,ll>>> slopeneg1;
    for(ll i=0;i<n;i++) {
        pair<ll,ll> tempp={1,arr[i].second-arr[i].first};
        for(ll j=0;j<n;j++) {
            if(linept(tempp,arr[j])) {
                slope1[tempp].insert(arr[j]);
            }
        }
    }
    for(ll i=0;i<n;i++) {
        pair<ll,ll> tempp={-1,arr[i].second+arr[i].first};
        for(ll j=0;j<n;j++) {
            if(linept(tempp,arr[j])) {
                slopeneg1[tempp].insert(arr[j]);
            }
        }
    }
    ll anss=0;
    for(auto x:slope1) {
        anss=max(anss,(ll)x.second.size());
    }
    ll ansc=0;
    for(auto x:slopeneg1) {
        ansc=max(ansc,(ll)x.second.size());
    }
    ll ans3=(2*n)-anss-ansc;


    map<pair<ll,ll>,set<pair<ll,ll>>> slope0;
    map<pair<ll,ll>,set<pair<ll,ll>>> slopeinf;
    for(ll i=0;i<n;i++) {
        pair<ll,ll> tempp={0,arr[i].second};
        for(ll j=0;j<n;j++) {
            if(linept(tempp,arr[j])) {
                slope0[tempp].insert(arr[j]);
            }
        }
    }
    for(ll i=0;i<n;i++) {
        pair<ll,ll> tempp={inf,-arr[i].first};
        for(ll j=0;j<n;j++) {
            if(linept(tempp,arr[j])) {
                slopeinf[tempp].insert(arr[j]);
            }
        }
    }
    ll ans11=0;
    ll ans12=0;
    for(auto x:slope0) ans11=max(ans11,(ll)x.second.size());
    for(auto x:slopeinf) ans12=max(ans12,(ll)x.second.size());
    ll ans4=(2*n)-ans11-ans12;
    cout<<min({ans3,ans4,ans2,((2*n)-third)})<<endl;
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