/*
    author:Karan
    created:16.08.2022 11:14:18
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

const int inf = 1e9+10;
const int mx = 110;
bool visited[mx][mx];
int a[4] = {-1, 0, 1, 0};
int b[4] = {0, 1, 0, -1};

bool isGood(int i, int j, int n, vector<string> & arr) {
    if (i < 0 || j >= n || i >= n || j < 0) {
        return false;
    }
    if(arr[i][j]=='V') {
        return false;
    }
    if (visited[i][j]) {
        return false;
    }
    return true;
}

void solve() {
    int n;
    cin>>n;
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=n;j++) {
            visited[i][j]=false;
        }
    }
    vector<string> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    vector<vector<int>> time(n, vector<int> (n, inf));
    time[0][0]=0;
    queue<pair<int,int>> q;
    q.push({0,0});
    while(q.size()) {
        pair<int,int> u=q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            pair<int,int> v=make_pair(u.first+a[i],u.second+b[i]);
            if(isGood(v.first,v.second,n, arr)) {
                visited[v.first][v.second]=true;
                q.push(v);
                time[v.first][v.second]=time[u.first][u.second]+1;
            }
        }
    }
    (time[n-1][n-1]==inf)? cout<<-1<<endl: cout<<time[n-1][n-1]<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}