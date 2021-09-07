#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> row(n);
    vector<int> column(m);
    for(int i=0;i<n;i++) {
        cin>>row[i];
    }
    for(int j=0;j<m;j++) {
        cin>>column[j];
    }
    int ans=0;
    for(int i=0;i<n;i++) {
       if(find(column.begin(),column.end(),row[i])!=column.end()) {
           ans++;
       }
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
}