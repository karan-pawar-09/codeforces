/*
    author:Karan
    created:27.05.2023 17:30:49
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

bool equal(char a, char b) {
    if(a==b) {
        return true;
    }
    if(a == 'l') {
        if(b=='1') {
            return true;
        }
    }
    if(a=='1') {
        if(b=='l') return true;
    }
    if(a=='0') {
        if(b=='o') return true;
    }
    if(a=='o') {
        if(b=='0') return true;
    }
    return false;
}
void solve() {
    int n;
    cin >> n;
    string s, t;
    cin>>s;
    cin>>t;
    for(int i=0;i<n;i++) {
        if(equal(s[i], t[i])) {

        } else {
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
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