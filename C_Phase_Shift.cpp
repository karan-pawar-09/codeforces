/*
    author:Karan
    created:07.10.2022 01:11:55
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

struct DSU {
    vector<ll> parent;
    vector<ll> magnitude;
    DSU(ll n) {
        parent.resize(n+1);
        magnitude.resize(n+1);
        for(ll i=1;i<=n;i++) {
            make_set(i);
        }
    }

    ll find(ll v) {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }

    void make_set(ll v) {
        parent[v] = v;
        magnitude[v] = 1;
    }

    void merge(ll a, ll b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (magnitude[a] < magnitude[b])
                swap(a, b);
            parent[b] = a;
            magnitude[a] += magnitude[b];
        }
    }
};

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    DSU dsu = DSU(200);
    vector<bool> used(150, false);
    map<char, char> M;
    for(char c = 'a'; c<= 'z'; c++) {
        M[c] = c;
    }
    string ans = "";
    int count = 0;
    for(int i=0;i<n;i++) {
        if(M[s[i]] == s[i]) {
            for(char c = 'a'; c <= 'z'; c++) {
                if(!used[c] && s[i] != c) {
                    if(dsu.find(c) == dsu.find(s[i]) && count < 25) {
                        
                    } else {
                        M[s[i]] = c;
                        ans += c;
                        used[c] = true;
                        dsu.merge(c, s[i]);
                        count ++;
                        break;
                    }
                }
            }
          
        } else {
            ans += M[s[i]];
        }
    }

    cout<<ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}