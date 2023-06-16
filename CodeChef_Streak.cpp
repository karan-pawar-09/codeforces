/*
    author:Karan
    created:14.06.2023 20:01:42
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
    cin >> n;
    vector<int> a(n), b(n);
    
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i = 0; i < n;i++) {
        cin>>b[i];
    }
    int count = 0;
    int maxione = 0;
    for(int i=0;i<n;i++) {
        if(a[i]!=0) {
            count++;
        } else {
            count = 0;
        }
        maxione = max(maxione, count);
    }
    count = 0;
    int maxitwo = 0;
    for(int i =0; i<n;i++) {
        if(b[i] != 0) {
            count++;
        } else {
            count = 0;
        }
        maxitwo = max(maxitwo, count);
    }
    if(maxione > maxitwo) {
        cout<<"Om"<<endl;
    } else if(maxione < maxitwo) {
        cout<<"Addy"<<endl;
    } else {
        cout<<"Draw"<<endl;
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