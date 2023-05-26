/*
    author:Karan
    created:03.03.2023 14:29:48
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

void solve() {
    int n;
    cin >> n;
    string s;
    cin>>s;
    int ans = 1;
    
    for(int i=2;i<n;i++) {
        
        if(i>=2 && s.substr(i, 2) == s.substr(i-2, 2)) {

        } else if(i>=2 && s[i-2] == s[i]) {

        } else {
            ans++;
        }
    }
    cout<<ans<<endl;
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