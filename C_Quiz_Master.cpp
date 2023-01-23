/*
    author:Karan
    created:21.01.2023 20:38:42
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

const ll mx = 1e5+10;
const ll inf = 1e18+10;
vector<vector<ll>> factors(mx);

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> arr(n);
    vector<ll> freq(mx, 0);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    sort(all(arr));
    ll j = 0;
    ll nums = 0;
    for(auto x: factors[arr[j]]) {
        if(x <= m) {
            freq[x]++;
            if(freq[x] == 1) {
                nums++;
            }
        }
    }
    
    ll ans = inf;
    for(ll i=0;i<n;i++) {
        while(j<n && nums < m) {
            j++;
            if(j >= n) {
                break;
            }
            for(auto x: factors[arr[j]]) {
                if(x <= m) {
                    freq[x]++;
                    if(freq[x] == 1) {
                        nums++;
                    }
                }
            }
        }
        if(j<n) {
            ans = min(ans, arr[j]-arr[i]);
        }
        for(auto x: factors[arr[i]]) {
            if(x <= m) {
                freq[x]--;
                if(freq[x] == 0) {
                    nums--;
                }
            }
        }
    }

    (ans != inf) ? cout<<ans<<endl:cout<<-1<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    for(ll i=1;i<mx;i++) {
        for(ll j=i;j<mx;j+=i) {
            factors[j].push_back(i);
        }
    }
    ll t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}