/*
    author:Karan
    created:04.01.2022 18:08:45
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
    int n,a,b;
    cin>>n>>a>>b;
    int res=n-b-1;
    int res1=a-2;
    if((res+res1)%2 or res<0 or res1<0) {
        cout<<"First"<<endl;
    } else {
        cout<<"Second"<<endl;
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