/*
    author:Karan
    created:28.01.2023 17:31:07
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
    int a, b;
    a = 0;
    b = 0;
    for(int i=0;i<n;i++) {
        cin>>s;
        if(s=="For") {
            a++;
        } else {
            b++;
        }
    }
    if(a> b) {
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }
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