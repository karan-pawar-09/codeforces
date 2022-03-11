/*
    author:Karan
    created:26.02.2022 17:33:57
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
    int n,m;
    cin>>n>>m;
    map<int,int> M;
    for(int i=0;i<n;i++) {
        int a;
        cin>>a;
        M[a]++;
    }
    bool ans=true;
    for(int i=0;i<m;i++) {
        int a;
        cin>>a;
        if(M.find(a)!=M.end()) {
            if(M[a]>0) {
                M[a]--;
            } else {
                ans=false;
            }
        } else {
            ans=false;
        }
    }
    ans?cout<<"Yes"<<endl:cout<<"No"<<endl;
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