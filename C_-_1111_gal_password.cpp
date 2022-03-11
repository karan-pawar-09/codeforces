/*
    author:Karan
    created:05.03.2022 17:42:43
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

const ll mod= 998244353;
set<string> st;
int n;
void rec(int i,string s) {
    if(s.size()==n) {
        st.insert(s);
        return;
    }
    rec(i+1,s+s.back());
    if(s.back()!='9') {
        rec(i+1,s+(char)('0'+(s.back()-'0'+1)));
    }
    if(s.back()!='1') {
        rec(i+1,s+(char)('0'+(s.back()-'0'-1)));
    }
}
void solve() {
    cin>>n;
    for(int i=1;i<10;i++) {
        rec(1,to_string(i));
    }
    cout<<st.size()<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    while(t--) {
        solve();
    }
}