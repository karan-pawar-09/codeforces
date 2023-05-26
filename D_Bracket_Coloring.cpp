/*
    author:Karan
    created:25.05.2023 20:38:16
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

bool isOk(string &s) {
    int one = 0;
    int two = 0;
    for(auto x: s) {
        if(x=='(') {
            one++;
        } else {
            two++;
        }
    }
    return one==two;
}
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(isOk(s)) {
        int opening = 0;
        set<int> st;
        vector<int> ans;
        for(auto x: s) {
            if(x=='(') {
                if(opening >= 0) {
                    st.insert(1);
                    ans.push_back(1);
                } else {
                    st.insert(2);
                    ans.push_back(2);
                }
                opening++;
                // st.insert(1);
                // ans.push_back(1);
                // cout<<1<<" ";
            } else {
                if(opening > 0) {
                    opening--;
                    // cout<<1<<" ";
                    st.insert(1);
                    ans.push_back(1);
                } else {
                    //cout<<2<<" ";
                    st.insert(2);
                    ans.push_back(2);
                    opening--;
                }
            }
        }
        cout<<st.size()<<endl;
        if(st.size()==1) {
            for(auto &x: ans) {
                x = 1;
            }
        }
        for(auto x: ans) {
            cout<<x<<" ";
        }
        cout<<endl;
    } else {
        cout<<-1<<endl;
    }
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