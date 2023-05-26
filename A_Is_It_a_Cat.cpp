/*
    author:Karan
    created:03.03.2023 14:02:09
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

const string st = "meow";

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(auto &x: s) {
        x = (char)tolower(x);
    }
    string temp;
    temp.push_back(s[0]);
    for(int i=1;i<n;i++) {
        if(s[i] != s[i-1]) {
            temp.push_back(s[i]);
        }
    }
    s = temp;
    n = s.size();
    bool ans = false;
    if(s == st) {
        ans = true;
    }
    for(auto x: s) {
        if(x=='m' || x=='e' || x=='o' || x == 'w') {

        } else {
            ans = false;
        }
    }
    if(ans) {
        cout<<"YES"<<endl;
    } else
        cout<<"NO"<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}