/*
    author:Karan
    created:03.03.2023 14:15:15
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
    int n , k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<char, int> M;
    for(auto x: s) {
        M[x]++;
    }
    int ans = 0;
    for(char c = 'a'; c <= 'z'; c++) {
        int temp = min(M[c], M[c-'a' + 'A']);
        ans += temp;
        M[c] -= temp;
        M[c-'a' + 'A'] -= temp;
    }
    for(char c = 'a'; c <= 'z'; c++) {
        int temp = max(M[c], M[c-'a' + 'A']);
        if(temp/2 <= k) {
            ans += temp/2;
            k -= temp/2;
        } else {
            ans += k;
            k = 0;
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