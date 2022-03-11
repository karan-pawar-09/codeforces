/*
    author:Karan
    created:24.02.2022 16:02:26
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
    string s;
    cin>>s;
    reverse(all(s));
    string t=s;
    reverse(all(s));
    int indx=0;
    deque<char> dq;
    for(auto x:s) {
        dq.push_back(x);
    }
    int res=0;
    for(int i=0;i<s.size();i++) {
        if(t[indx]==s[i]) {
            res++;
            indx++;
        }
    }
    cout<<s.size()-res<<endl;
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