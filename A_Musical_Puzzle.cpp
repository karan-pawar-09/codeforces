/*
    author:Karan
    created:19.06.2023 20:47:15
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
    cin >> s;
    set<string> st;
    for(int i = 0; i < n - 1; i++) {
        st.insert(s.substr(i, 2));
    }
    cout<<st.size()<<endl;
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