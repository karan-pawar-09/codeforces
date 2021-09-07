/*
author:Karan
created:05.09.2021 20:06:27
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    string ans;
    for(int i=0;i<n;i++) {
        if(s[i]=='U') {
            ans.push_back('D');
        }
        else if(s[i]=='D') {
            ans.push_back('U');
        }
        else {
            ans.push_back(s[i]);
        }
    }
    cout<<ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
}