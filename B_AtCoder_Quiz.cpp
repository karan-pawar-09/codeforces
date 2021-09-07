/*
author:Karan
created:04.09.2021 21:16:29
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3;
    set<string> t;
    t.insert(s1);
    t.insert(s2);
    t.insert(s3);
    set<string> s;
    s.insert("ABC");
    s.insert("AHC");
    s.insert("ARC");
    s.insert("AGC");
    for(auto x:s) {
        if(t.find(x)==t.end()) {
            cout<<x<<endl;
            break;
        }
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