/*
    author:Karan
    created:31.01.2023 22:22:39
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

const ll mx = 2e5+10;
ll dp[mx];
bool visited[mx];
ll inCycle;
ll cycleSize[mx];
bool isInCycle[mx];
ll noofCycles;

void kahn(vector<ll> &in, ll n, vector<ll> &arr) {
    queue<ll> q;
    vector<bool> used(n+1, false);
    for(ll i=1;i<=n;i++) {
        
        if(in[i] == 0) {
            q.push(i);
            dp[i] = 0;
        }
    }
  
    while(q.size()) {
        ll v = q.front();
       
        used[v] = true;
        q.pop();
        ll p = arr[v] + v;
        
        if(p>=1 && p<=n) {
            in[p]--;
            dp[p] += dp[v] + 1;
            if(!in[p]) {
                q.push(p);
            }
        }
    }

    for(ll i=1;i<=n;i++) {
        if(!used[i] && dp[i]) {
            noofCycles++;
            ll val = dp[i];
            ll k = i + arr[i];
            ll size = 1;
            while(k != i) {
                size++;
                k = k + arr[k];
            }
            inCycle += size+1;
            used[i] = true;
            // dp[i] = val + size -1;
            isInCycle[i] = true;
            cycleSize[i] = size;
            k = i + arr[i];
            while(k != i) {
                used[k] = true;
                //dp[k] = val + size -1;
                cycleSize[k] = size;
                isInCycle[i] = true;
                k = k + arr[k];
            }
        }
    }

    for(ll i=1;i<=n;i++) {
        if(!used[i]) {
            noofCycles++;
            ll k = i + arr[i];
            ll size = 1;
            while(k != i) {
                size++;
                k = k + arr[k];
            }
            inCycle += size;
            used[i] = true;
            //dp[i] = size -1;
            isInCycle[i] = true;
            cycleSize[i] = size;
            k = i + arr[i];
            while(k != i) {
                used[k] = true;
                //dp[k] = size -1;
                cycleSize[k] = size;
                isInCycle[i] = true;
                k = k + arr[k];
            }
        }
    }

}

void dfs(ll node, vector<ll> &arr, ll n) {
    visited[node] = true;
    ll p = node + arr[node];
    if((p >=1) && (p <= n) && !visited[p]) {
        dfs(p, arr, n);
    }
}

void solve() {
    ll n;
    cin>>n;
    vector<ll> arr(n+1);
    vector<ll> in(n+1);
    inCycle = 0;
    noofCycles = 0;
    dp[0] = 0;
    visited[0] = false;
    for(ll i=1;i<=n;i++) {
        dp[i] = 0;
        isInCycle[i] = false;
        cycleSize[i] = 0;
        visited[i] = false;
        cin>>arr[i];
        ll p = i+arr[i];
        if(p>=1 && p<=n) {
            in[p]++;
        }
    }
    kahn(in, n, arr);
    dfs(1, arr, n);
    //cout<<inCycle<<endl;
    ll ress = 0;
    for(ll i=1;i<=n;i++) {
        if(cycleSize[i] && visited[i]) {
            ress++;
        }
    }
    ll ans = 0;
    bool broken = false;
    ll index = -1;
    for(ll i = 1;i<=n;i++) {
        if(visited[i] && cycleSize[i]) {
            broken = true;
            index = i;
            break;
        }
        
    }
    //cout<<inCycle<<" "<<dp[1]<<noofCycles<<endl;
    if(broken) {
        for(int i=1;i<=n;i++) {
            
            if(visited[i]) {
                ll temp = 2*n+1;
                temp -= inCycle + dp[i];
                if(visited[i] && ((cycleSize[i]==0))) {
                    temp--;
                }
                ans += temp;
            }
        }
    } else {
    //    for(int i=1;i<=n;i++) {
    //     cout<<dp[i]<<" ";
    //    }
    //    cout<<endl;
        for(ll i=1; i<=n;i++) {
            ll temp = 2*n+1;
            if(visited[i]) {
                temp -= inCycle + dp[i];
                if(visited[i] && ((cycleSize[i]==0))) {
                    temp--;
                }
            }

            //cout<<i<<" "<<temp<<endl;
        
            //cout<<i<<" "<<temp<<" "<<dp[i]<<" "<<ress<<endl;
            ans += temp;
        }
    }
    
    cout<<ans<<endl;
    //cout<<"----------------------"<<endl;
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
