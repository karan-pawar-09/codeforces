/*
    author:Karan
    created:12.08.2022 20:54:23
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

vector<int> findDataLocations(vector<int> locations, vector<int> movedFrom, vector<int> movedTo) {
    int n = locations.size();
    int m = movedFrom.size();
    multiset<int> s (locations.begin(), locations.end());
    for(int i=0;i<m;i++) {
        s.erase(s.find(movedFrom[i]));
        s.insert(movedTo[i]);
    }
    vector<int> ans(s.begin(), s.end());
    return ans;
}
void solve() {
    int n;
    cin>>n;
    vector<int> locations(n);
    for(int i=0;i<n;i++) {
        cin>>locations[i];
    }
    int m;
    cin>>m;
    vector<int> movedfrom(m), movedto(m);
    for(int i=0;i<m;i++) cin>>movedfrom[i];
    for(int i=0;i<m;i++) cin>>movedto[i];
    vector<int> ans = findDataLocations(locations, movedfrom, movedto);
    for(auto x: ans) {
        cout<<x<<" ";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}