/*
    author:Karan
    created:20.06.2023 21:16:50
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

const ll mx = 2e5 + 10;
vector<ll> val[mx];
vector<ll> val1[mx];
set<ll> st;

void solve() {
    ll n;
    cin >> n;
    st.clear();
    for(ll i = 0; i <= n;i++) {
        val[i].push_back(0);
        val[i].push_back(0);
        val1[i].push_back(0);
        val1[i].push_back(0);
    }
    ll nodes = 1;
    val[1] = {1, 1};
    val1[1] = {0 , 0};
    nodes++;
    while(n--) {
        char c;
        cin >> c;
        if(c == '+') {
            ll v, x;
            cin >> v >> x;
            ll first = x + (val[v][0] > 0 ? val[v][0] : 0);
            ll second = max(val[v][1], first);
            val[nodes] = {first, second};
            first = x + (val1[v][0] < 0 ? val1[v][0] : 0);
            second = min(val1[v][1], first);
            val1[nodes] = {first, second};
            nodes++;
        } else {
            ll u, v, k;
            cin >> u >> v >> k;
            if(k == 0) {
                cout<<"YES"<<endl;
            } else if(k > 0) {
                if(k <= val[v][1]) {
                    cout<<"YES"<<endl;
                } else {
                    cout<<"NO"<<endl;
                }
            } else {
                if(k >= val1[v][1]) {
                    cout<<"YES"<<endl;
                } else {
                    cout<<"NO"<<endl;
                }
            }
        }
    }

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