/*
    author:Karan
    created:25.08.2022 20:16:49
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

const int inf = 1e9+10;

int findmini(vector<int> &latest) {
    int minimum = inf;
    for(int i=0;i<26;i++) {
        minimum = min(minimum, latest[('a'+i)]);
    }
    return minimum;
}

void solve() {
    string s;
    cin>>s;
    vector<int> latest(150, inf);
    set<char> st;
    for(auto x: s) {
        st.insert(x);
    }
    int count = st.size();
    set<char> p;
    int res = s.size();
    int lowest = 0;
    for(int i=0;i<s.size();i++) {
        p.insert(s[i]);
        if(p.size() < count) {
            latest[s[i]]=i;
        } else {
            res = min(res, i+1);
            if(latest[s[i]] == lowest) {
                latest[s[i]] = i;
                lowest = findmini(latest);
                res = min(res, (i-lowest)+1);
            } else {
                latest[s[i]] = i;
            }
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

// ajjalfjlajfljlkasjdfj

