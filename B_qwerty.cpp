/*
    author:Karan
    created:11.09.2021 17:32:23
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    vector<int> p(26);
    for(int i=0;i<26;i++) {
        cin>>p[i];
        cout<<(char)('a'+(p[i]-1));
    }
    cout<<endl;
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