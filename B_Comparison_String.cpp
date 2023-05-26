/*
    author:Karan
    created:25.05.2023 20:10:49
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
    int count = 1;
    int maxi = 1;
    for(int i=1;i<n;i++) {
        if(s[i]==s[i-1]) {
            count++;
        } else {
            count = 1;
        }
        maxi = max(count, maxi);
    }
    cout<<maxi+1<<endl;
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