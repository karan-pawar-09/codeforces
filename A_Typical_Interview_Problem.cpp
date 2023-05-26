/*
    author:Karan
    created:01.03.2023 11:36:39
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

string s;

void solve() {
    int n;
    cin >> n;
    string k;
    cin >> k;
    for(int i=0;i<s.size()-n;i++) {
        if(s.substr(i, n) == k) {
            cout<<"YES"<<endl;
            return;
        }
    }
    
    cout<<"NO"<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    for(int i=0;i<50;i++) {
        if(i%3==0) s.push_back('F');
        if(i%5==0) s.push_back('B');
    }
    while(t--) {
        solve();
    }
}