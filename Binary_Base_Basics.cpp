/*
    author:Karan
    created:05.02.2022 10:58:51
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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int req=0;
    for(int i=0;i<n/2;i++) {
        if(s[i]!=s[n-1-i]) {
            req++;
        }
    }
    if((k-req)>=0 and ((k-req)%2==0 or n%2)) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO" <<endl;
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