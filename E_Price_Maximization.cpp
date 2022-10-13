/*
    author:Karan
    created:09.06.2022 22:17:21
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

ll binarySearch(vector<pair<ll,ll>> &arr, ll k, ll index) {
    ll l=index;
    ll r=arr.size();
    while(l+1 < r) {
        ll m= l+(r-l)/2;
        if((arr[index].first+arr[m].first)>=k) {
            l=m;
        } else {
            r=m;
        }
    }
    return l;
}

void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    vector<pair<ll,ll>> ar(n);
    vector<multiset<ll>> mp(k);
    for(ll i=0;i<n;i++) {
        ar[i].first=arr[i]%k;
        ar[i].second=arr[i];
        mp[arr[i]%k].insert(arr[i]);
    }
    sort(all(ar),greater<pair<ll,ll>>());
    ll ans=0;
    ll l=1;
    ll r=k-1;
    while(l<=r) {
        ll one=0;
        ll two=0;
        bool oneset=false;
        bool twoset=false;
        if(r>=l && mp[r].size()) {
            one=*mp[r].begin();
            oneset=true;
            mp[r].erase(mp[r].begin());
        }
        else {
            while(r>l && !mp[r].size()) {
                r--;
            }
            if(r>=l) {
                if(mp[r].size()) {
                    one=*mp[r].begin();
                    oneset=true;
                    mp[r].erase(mp[r].begin());
                }
            }
        }
        if(l<=r && mp[l].size() && (l+r)>=k) {
            two=*mp[l].begin();
            twoset=true;
            mp[l].erase(mp[l].begin());
        } else {
            while((l<r && mp[l].size()==0) || (l<r&&(l+r)<k)) {
                l++;
            }
            if(l<=r) {
                if(mp[l].size() && (l+r)>=k) {
                    two=*mp[l].begin();
                    twoset=true;
                    mp[l].erase(mp[l].begin());
                }
            }
        }
        ans+=(one+two)/k;
        if(!(oneset||twoset)) break;
    }
    for(ll i=0;i<k;i++) {
        for(auto x:mp[i]) {
            ans+=x/k;
        }
    }
    cout<<ans<<endl;
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