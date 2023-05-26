/*
author:Karan
created:23.08.2021 22:20:42
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

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

//------------------------------------------------------------------------------------------------------------//
struct testcase {
    ll n;
    vector<ll> arr;
};

ll randomNumber(ll a, ll b) {
    return a + (rand() % b);
}

string randomString(const ll len) {

    string tmp_s;
    static const char alphanum[] =
        "1234567890";
    // "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    // "abcdefghijklmnopqrstuvwxyz";

// srand( (unsigned) time(NULL) * getpid());
    tmp_s.reserve(len);
    for (ll i = 0; i < len; ++i) {
        if (i == 0) {
            tmp_s += alphanum[rand() % (sizeof(alphanum) - 2)];
        }
        else
            tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}

vector<vector<ll>> randomMatrix(const ll n) {
    srand(time(0));
    vector<vector<ll>> ans(n);
    for (ll i = 0;i < n;i++) {
        ll p = randomNumber(1, 9);
        ans[i].push_back(p);
        for (ll j = 0;j < p;j++) {
            ll q = randomNumber(1, 10);
            ans[i].push_back(q);
        }
    }

    return ans;
}
vector<ll> randomArray(const ll n, ll x) {
    vector<ll> ans(n);
    for (ll i = 0;i < n;i++) {
        ll p = randomNumber(-n, 2*n+1);
        // ll x=randomNumber(0,2);   //for -ve no
        // if(x==0) p=-p;
        ans[i] = p;
    }
    return ans;
}
testcase generateTestCase() {
    testcase randomTest;
    randomTest.n = randomNumber(1, 3);
    randomTest.arr = randomArray(randomTest.n, randomTest.n);
    return randomTest;
}


ll  bruteForce(testcase T) {
    ll n = T.n;
    vector<ll> arr = T.arr;
    vector<ll> tempoRR;
    tempoRR.push_back(0);
    for(auto x: arr) {
        tempoRR.push_back(x);
    }
    arr = tempoRR;
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
    
    return ans;
    
}

ll  optimizedSolution(testcase T) {
    ll n = T.n;
    vector<ll> a = T.arr;
    for (ll i = 0; i < n; i++) {
      cin >> a[i];
      a[i] += i;
    }
    vector<vector<ll>> g(n);
    for (ll i = 0; i < n; i++) {
      if (0 <= a[i] && a[i] < n) {
        g[a[i]].push_back(i);
      }
    }
    ll left = n;
    vector<ll> sz(n, 0);
    function<void(ll)> Dfs = [&](ll v) {
      left -= 1;
      sz[v] = 1;
      for (ll u : g[v]) {
        Dfs(u);
        sz[v] += sz[u];
      }
    };
    for (ll i = 0; i < n; i++) {
      if (a[i] < 0 || a[i] >= n) {
        Dfs(i);
      }
    }
    long long ans = 0;
    if (sz[0] == 0) {
      vector<ll> was(n, 0);
      ll x = 0;
      ll cnt = 0;
      while (!was[x]) {
        was[x] = 1;
        cnt += 1;
        x = a[x];
      }
      ans = (long long) cnt * (2 * n + 1 - left);
    } else {
      ll x = 0;
      ll cnt = 0;
      while (0 <= x && x < n) {
        ans += n - left - sz[x] + (n + 1);
        cnt += 1;
        x = a[x];
      }
      ans += (long long) (n - cnt) * (2 * n + 1);
    }
    return ans;
}

bool debugger(ll& t) {
    testcase random = generateTestCase();
    // cout<<random.s<<" ";
    ll  answ1 = bruteForce(random);
    ll  answ2 = optimizedSolution(random);
    if (answ1 != answ2) {
        cout << "WA on testcase " << t << endl;
        
        
       
        cout<<random.n<<endl;
        for(auto x: random.arr) {
            cout<<x<<" ";
        }
        cout<<endl;
        cout<<answ1<<" "<<answ2<<endl;
       
       
        return false;
    }
    else {
        cout << "AC on testcase " << t << endl;
        cout << endl;
        return true;
    }
}


bool solve(ll& t) {
    if (!debugger(t)) {
        return false;
    }
    else {
        return true;
    }
}

int32_t main() {
    ll t;
    cin >> t;
    for (ll i = 1;i <= t;i++) {
        if (!solve(i)) break;
    }
    return 0;
}