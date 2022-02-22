/*
    author:Karan
    created:13.02.2022 13:25:08
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
    if(n%2) {
        set<char>st;
        int one=0;
        int zero=0;
        for(auto x:s) {
            st.insert(x);
            if(x=='1') one++;
            else zero++;
        }
        if(st.size()==1) {
            cout<<"YES"<<endl;
        } else {
            if(one==1 or zero==1) {
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;
        }
    } else {
        set<char> st;
        int one=0;
        int zero=0;
        for(auto x:s) {
            st.insert(x);
            if(x=='1') one++;
            else zero++;
        }
        if(st.size()==1) {
            cout<<"YES"<<endl;
        } else {
            if(one==zero) {
                cout<<"YES"<<endl;
            } else {
                cout<<"NO"<<endl;
            }
        }
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