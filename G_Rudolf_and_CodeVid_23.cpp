/*
    author:Karan
    created:08.07.2023 09:21:00
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

const int INF = 1e9 + 10;

int stringToInt(string& s, int n) {
    int temp = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            temp |= (1 << i);
        }
    }
    return temp;
}

int dijkstra(int start, vector<pair<int, pair<int, int>>>& arr, int n) {
    vector<int> dist(1 << n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({ 0, start });
    dist[start] = 0;
    while (q.size()) {
        pair<int, int> pi = q.top();
        int node = pi.second;
        int d = pi.first;
        q.pop();
        if (dist[node] != d) continue;
        for (auto x : arr) {
            int newNode = node - (node & x.second.first);
            newNode |= x.second.second;
            int newD = d + x.first;
            if (newD < dist[newNode]) {
                dist[newNode] = newD;
                q.push({ newD, newNode });
            }
        }
    }
    return dist[0] == INF ? -1 : dist[0];
}

void solve() {
    int n, m;
    cin >> n >> m;
    string s, temp1, temp2;
    cin >> s;
    int start = stringToInt(s, n);
    vector<pair<int, pair<int, int>>> arr(m);
    for (int i = 0; i < m; i++) {
        cin >> arr[i].first;
        cin >> temp1 >> temp2;
        arr[i].second.first = stringToInt(temp1, n);
        arr[i].second.second = stringToInt(temp2, n);
    }
    cout << dijkstra(start, arr, n) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}