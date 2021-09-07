/*
author:Karan
created:28.08.2021 21:22:39
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

ll V;

ll findMaxVertex(vector<bool> &visited, vector<ll> &weights) {
 
    ll index = -1;
    ll maxW = INT_MIN;

    for (ll i = 0; i < V; i++) {
        if (visited[i] == false
            && weights[i] > maxW) {
 
            // Update maxW
            maxW = weights[i];
 
            // Update index
            index = i;
        }
    }
    return index;
}
 

ll printMaximumSpanningTree(vector<vector<ll>> &graph,vector<ll> &parent) { 
  
    ll MST = 0;
    for (ll i = 1; i < V; i++) {
        MST += graph[i][parent[i]];
    }
    return MST;
}
 
ll maximumSpanningTree(vector<vector<ll>> &graph)
{

    vector<bool> visited(V);
    vector<ll> weights(V);
    vector<ll> parent(V);
    for (ll i = 0; i < V; i++) {
        visited[i] = false;
        weights[i] = INT_MIN;
    }
    weights[0] = INT_MAX;
    parent[0] = -1;
    for (ll i = 0; i < V - 1; i++) {
        ll maxVertexIndex
            = findMaxVertex(visited, weights);
        visited[maxVertexIndex] = true;
        for (ll j = 0; j < V; j++) {
            if (graph[j][maxVertexIndex] != 0
                && visited[j] == false) {
                if (graph[j][maxVertexIndex] > weights[j]) {
                    weights[j] = graph[j][maxVertexIndex];
                    parent[j] = maxVertexIndex;
                }
            }
        }
    }
    return printMaximumSpanningTree(graph,parent);
}

ll LCSubStr(string &X, string &Y, ll m, ll n) {
 
    ll LCSuff[m + 1][n + 1];
    ll result = 0; 
    for (ll i = 0; i <= m; i++)
    {
        for (ll j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;
 
            else if (X[i - 1] == Y[j - 1]) {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                result = max(result, LCSuff[i][j]);
            }
            else
                LCSuff[i][j] = 0;
        }
    }
    return result;
}
const int mxx=101;
string arr[mxx];
void solve() {
    ll n;
    cin>>n;
    V=n;
    // vector<string> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    vector<vector<ll>> ar(n,vector<ll> (n,0));
    for(ll i=0;i<n;i++) {
        for(ll j=i+1;j<n;j++) {
            ar[i][j]=ar[j][i]=LCSubStr(arr[i],arr[j],arr[i].size(),arr[j].size());
        }
    }
    cout<<maximumSpanningTree(ar)<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        solve();
    }
}