
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

bool comp(pair<int,pair<int,int>> p1,pair<int,pair<int,int>> p2) {
    if(p1.second.first>p2.second.first) return true;
    else if(p1.second.first==p2.second.first) {
        if(p1.second.second<p2.second.second) {
            return true;
        }
        else {
            return false;
        }
    }
    return false;
}

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    unordered_map<int,pair<int,int>> M;
    for(int i=0;i<n;i++) {
        M[arr[i]].first++;
        if(M[arr[i]].first==1)
            M[arr[i]].second=i;
    }
    vector<pair<int,pair<int,int>>> ans;
    for(auto x:M) {
        ans.push_back({x.first,{x.second.first,x.second.second}});
    }
    sort(all(ans),comp);
    for(int i=0;i<ans.size();i++) {
        for(int j=0;j<ans[i].second.first;j++) {
            cout<<ans[i].first<<" ";
        }
    }
    cout<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    solve();    
}
