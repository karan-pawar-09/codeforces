/*
    author:Karan
    created:08.02.2023 22:01:42
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

int check(string &s, char c, int k) {
    int start = 0;
    int end = -1;
    int freq = 0;
    int res = 0;
    while(start<= end && end<s.size()) {
        if(s[start] == c) {
            freq++;
        }
        if((2*freq - (start-end)) == k) {
            res++;
            start++;
        } else if((2*freq - (start-end)) > k) {
            start++;
        } else {
            if(end >= 0 &&s[end] == c) {
                freq--;
            }
            end++;
        }
    }
    return res;
}
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin>>s;
    int ans = 0;
    for(char c = 'a'; c<= 'z'; c++) {
        ans += check(s, c, k);
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