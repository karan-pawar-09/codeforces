/*
    author:Karan
    created:07.09.2021 17:56:49
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    int n;
    cin>>n;
    set<pair<string,string>> arr;
    bool ans=false;
    pair<string,string> s;
    for(int i=0;i<n;i++) {
        cin>>s.first>>s.second;
        if(arr.find(s)!=arr.end()) {
            ans=true;
        }
        arr.insert(s);
    }
    if(ans) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
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