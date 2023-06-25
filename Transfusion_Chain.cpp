/*
    author:Karan
    created:21.06.2023 20:02:25
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

void solve() {
    ll n;
    cin >> n;
    vector<string> arr(n);
    map<string, ll> M;
    map<string, bool> DP;
    DP["A"] = false;
    DP["B"] = false;
    DP["AB"] = false;
    DP["O"] = false;
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        M[arr[i]]++;
        DP[arr[i]] = true;
    }
    bool AB = false;
    if(M.find("A") != M.end()) {
        AB = true;
    } 
    if(M.find("B") != M.end()) {
        AB = true;
    }
    M["A"] += M["AB"];
    M["B"] += M["AB"];
    cout<<max(M["O"] + M["A"], M["O"] + M["B"])<<endl;
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