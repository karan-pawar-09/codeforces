/*
    author:Karan
    created:27.08.2022 20:12:28
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

const ll inf = 1e9+10;

ll aa[4] = {-1, 0, 1, 0};
ll bb[4] = {0, 1, 0, -1};

bool isGood(ll a, ll b, ll n, ll m, vector<vector<bool>> &visited, ll x, ll y, ll d) {
    if(a<=0 || a>n || b<=0 || b>m) return false;
    if(visited[a][b]) return false;
    if((abs(x-a) + abs(y-b)) <=d ) return false;
    return true;
}
void solve() {
    ll n,m, x,y, d;
    cin>>n>>m>>x>>y>>d;
    if((x==y) && (x==1)) {
        cout<<-1<<endl;
        return;
    }
    if(((abs(x+d) < n) && (y > (d+1))) || ((abs(y+d) < m) && (x >(d+1)))) {
        cout<<n+m-2<<endl;
    } else {
        cout<<-1<<endl;
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