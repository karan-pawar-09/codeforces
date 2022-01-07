/*
    author:Karan
    created:11.12.2021 16:37:21
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

void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n),b(n);
    vector<pair<pair<ll,ll>,ll>> arr(n);
    vector<pair<pair<ll,ll>,ll>> ar(n);
    for(ll i=0;i<n;i++) {
        cin>>a[i];
        arr[i].first.first=a[i];
        ar[i].first.second=a[i];
        arr[i].second=i;
        ar[i].second=i;
    }
    for(ll i=0;i<n;i++) {
        cin>>b[i];
        ar[i].first.first=b[i];
        arr[i].first.second=b[i];
    }
    ll maxi=0;
    ll index=0;
    ll mini=min(a[0],b[0]);
    for(ll i=0;i<n;i++) {
        if(a[i]<b[i]) swap(a[i],b[i]);
        if(max(a[i],b[i])>maxi) {
            maxi=max(a[i],b[i]);
            mini=min(a[i],b[i]);
            index=i;
        }
    }
    ;
    vector<bool> ans(n,false);
    ans[index]=true;
    set<pair<pair<ll,ll>,ll>,greater<pair<pair<ll,ll>,ll>>> s;
    for(ll i=0;i<n;i++) {
        if(i!=index) {
            s.insert({{a[i],b[i]},i});
        }
    }
    ll prevsize=s.size();
    bool k=true;
    while(k and s.size()) {
        vector<pair<pair<ll,ll>,ll>> z;
        for(auto x:s) {            
            if(max(x.first.first,x.first.second)>=mini) {
                ans[x.second]=true;
                if(min(x.first.first,x.first.second)<mini) {
                    mini=min(x.first.first,x.first.second);
                }
                z.push_back(x);
            }            
        }
        if(z.size()) {
            for(auto u:z) {
                s.erase(u);
            }
        }
        else {
            k=false;
            break;
        }
    }
    for(ll i=0;i<n;i++) {
        cout<<ans[i];
    }
    cout<<endl;
} 

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}






