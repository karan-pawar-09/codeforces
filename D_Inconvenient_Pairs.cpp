/*
    author:Karan
    created:10.09.2021 00:32:46
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const ll mx=1e6+7;

ll binarysearch(vector<ll> &arr,ll x) {
    ll r=arr.size()-1;
    ll l=-1;
    while(l+1<r) {
        ll m=l+(r-l)/2;
        if(arr[m]>=x) {
            r=m;
        }
        else {
            l=m;
        }
    }
    return r;
}

ll total(vector<ll> &height,vector<bool> &x_used,vector<bool> &y_used,vector<pair<ll,ll>> &pt) {
    map<ll,ll> M;
    ll ans=0;
    map<ll,ll> prevpt;
    map<ll,ll> temp;
    for(ll i=pt.size()-1;i>=0;i--) {
        if(x_used[pt[i].first] and !y_used[pt[i].second]) {
            ll no=binarysearch(height,pt[i].second);
            if(prevpt[height[no]]!=pt[i].first)
                M[height[no]]=temp[height[no]];
           
            if(M.find(height[no])!=M.end()) {
                {
                    ans+=M[height[no]];
                }
            }
            temp[height[no]]++;
            prevpt[height[no]]=pt[i].first;
        }
    }
    return ans;
}

void solve() {
    ll n,m,k;
    cin>>n>>m>>k;
    vector<bool> x_used(mx,false);
    vector<bool> y_used(mx,false);
    vector<ll> x(n);
    for(ll i=0;i<n;i++) {
        cin>>x[i];
        x_used[x[i]]=true;
    }
    vector<ll> y(m);
    for(ll i=0;i<m;i++) {
        cin>>y[i];
        y_used[y[i]]=true;
    }
    x.push_back(1e9);
    y.push_back(1e9);
    sort(all(x));
    sort(all(y));
    vector<pair<ll,ll>> ptx(k);
    vector<pair<ll,ll>> pty(k);
    for(ll i=0;i<k;i++) {
        cin>>ptx[i].first>>ptx[i].second;
        pty[i].first=ptx[i].second;
        pty[i].second=ptx[i].first;
    }
    sort(all(ptx));
    sort(all(pty));
    cout<<total(y,x_used,y_used,ptx)+total(x,y_used,x_used,pty)<<endl;
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