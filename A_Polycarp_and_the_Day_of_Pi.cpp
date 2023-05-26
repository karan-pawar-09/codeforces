/*
    author:Karan
    created:27.01.2023 20:07:20
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
    string st;
    cin>>st;
    int no = 22;
    int dev = 7;
    int k = 50;
    string s;
    while(k--) {
        int res = no%dev;
        int temp = no/dev;
        s.push_back('0'+temp);
        no = res* 10;
    }
    int ans = 0;
    //cout<<s<<endl;
    s = "314159265358979323846264338327950288419716939937510";
    for(int i=0;i<st.size();i++) {
        if(st[i] == s[i]) {
            ans++;
        } else {
            break;
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