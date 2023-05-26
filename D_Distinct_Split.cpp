/*
    author:Karan
    created:03.02.2023 20:14:40
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
    cin>>n;
    string s;
    cin>>s;
    map<char, int> M;
    for(auto x: s) {
        M[x]++;
    }
    map<char, int> N;
    int maxi = 0;
    for(int i=0;i<n-1;i++) {
        N[s[i]]++;
        M[s[i]]--;
        if(M[s[i]] == 0) {
            M.erase(s[i]);
        }
        int a = N.size();
        int b = M.size();
        maxi = max(maxi, a+b);
    }
    cout<<maxi<<endl;
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