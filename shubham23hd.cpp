/*
author:Karan
created:05.09.2021 17:22:38
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    int n;
    cin>>n;
    vector<string> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    string ans;
    for(int i=0;i<arr[0].size();i++) {
        int k=0;
        for(int j=0;j<arr.size();j++) {
            k=(k ^ (arr[j][i]-'0'));
        }
        ans.push_back('0'+k);
    }
    cout<<ans<<endl;
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