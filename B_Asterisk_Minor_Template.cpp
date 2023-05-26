/*
    author:Karan
    created:01.03.2023 19:45:28
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
    string a, b;
    cin >> a >> b;
    if(a[0] == b[0]) {
        cout<<"YES"<<endl;
        cout<<a[0]<<"*"<<endl;
        return;
    } 
    if(a.back() == b.back()) {
        cout<<"YES"<<endl;
        cout<<"*"<<a.back()<<endl;
        return;
    }
    for(int i=0;i<a.size()-1;i++) {
        string temp = a.substr(i, 2);
        for(int j=0;j<b.size()-1; j++) {
            if(b.substr(j, 2) == temp) {
                cout<<"YES"<<endl;
                cout<<"*"<<temp<<"*"<<endl;
                return;
            }
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
    while(t--) {
        solve();
    }
}