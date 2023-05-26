/*
    author:Karan
    created:28.01.2023 17:33:53
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
    int n, m;
    cin>>n>>m;
    vector<string> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    set<string> st;
    for(int i=0;i<m;i++) {
        string temp;
        cin>>temp;
        st.insert(temp);
    }
    int res = 0;
    for(int i=0;i<n;i++) {
        if(st.find(arr[i].substr(3)) != st.end()) {
            res++;
        }
    }
    cout<<res<<endl;
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