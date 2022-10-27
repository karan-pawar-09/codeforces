/*
    author:Karan
    created:16.10.2022 00:47:41
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

ll binarysearch(vector<ll> &a, ll x) {
    ll l = 0;
    ll r = a.size();
    while(l+1 < r) {
        ll m = l+(r-l)/2;
        if(a[m] <= x) {
            l = m;
        } else {
            r = m;
        }
    }
    if(a[l] <= x) {
        return a[l]+1;
    } else {
        return -1;
    }
}
ll binarysearch1(vector<ll> &a, ll x) {
    ll l = -1;
    ll r = a.size()-1;
    while((l+1) < r) {
        ll m = l+(r-l)/2;
        if(a[m]>=x) {
            r = m;
        } else {
            l = m;
        }
    }
    if(a[r]>=x) {
        return a[r]-1;
    } else {
        return -1;
    }
}
void solve() {
    ll h, w, starti, startj;
    cin>>h>>w>>startj>>starti;
    ll n;
    cin>>n;
    map<ll, vector<ll>> X, Y;
    for(ll i=0;i<n;i++) {
        ll a, b;
        cin>>b>>a;
        X[a].push_back(b);
        Y[b].push_back(a);
    }
    for(auto &x: X) {
        sort(all(x.second));
    }
    for(auto &y: Y) {
        sort(all(y.second));
    }
    ll q;
    cin>>q;
    while(q--) {
        char c;
        ll dist;
        cin>>c>>dist;
        if(c=='L') {
            ll next = starti-dist;
            ll res = -1;
            if(Y.find(startj) != Y.end()) {
                res = binarysearch(Y[startj], starti);
            }
            if(res == -1) {
                starti -= dist;
            } else {
                starti = max(starti-dist, res);
            }
        } else if(c == 'R') {
            ll next = starti + dist;
            ll res = -1;
            if(Y.find(startj) != Y.end()) {
                res = binarysearch1(Y[startj], starti);
            }
            if(res == -1) {
                starti += dist;
            } else {
                starti = min(starti+dist, res);
            }
        } else if(c == 'U') {
            ll next = startj -dist;
            ll res = -1;
            if(X.find(starti) != X.end()) {
                res = binarysearch(X[starti], startj);
            }
            if(res == -1) {
                startj -= dist;
            } else {
                startj = max(startj-dist, res);
            }
        } else {
            ll next = startj+dist;
            ll res = -1;
            if(X.find(starti) != X.end()) {
                res = binarysearch1(X[starti], startj);
            }
            if(res == -1) {
                startj += dist;
            } else {
                startj = min(startj+dist, res);
            }
        }
        
        starti = max(starti, 1LL);
        starti = min(starti, w);
        startj = max(startj, 1LL);
        startj = min(startj, h);
      
        cout<<startj<<" "<<starti<<endl;

    }
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