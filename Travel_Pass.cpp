/*
    author:Karan
    created:10.09.2021 16:34:12
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    int n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<n;i++) {
        if(s[i]=='0') ans+=a;
        else ans+=b;
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