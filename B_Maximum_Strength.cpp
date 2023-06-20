/*
    author:Karan
    created:18.06.2023 13:57:43
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
    string s1, s2;
    cin >> s1 >> s2;
    reverse(all(s1));
    reverse(all(s2));
    while(s1.size() < 200) s1.push_back('0');
    while(s2.size() < 200) s2.push_back('0');
    while((s1.size()) && (s1.back() == s2.back())) {
        s2.pop_back();
        s1.pop_back();
    }
    reverse(all(s1));
    reverse(all(s2));
    int ans = 0;
    for(int i = 1; i < s1.size(); i++) {
        ans += 9;
    }
    ans += abs(s1[0] - s2[0]);
    cout<<ans<<endl;  
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}

