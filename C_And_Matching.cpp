/*
    author:Karan
    created:27.01.2022 20:27:20
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
    if(k<=n/2) {
        vector<bool> used(n,false);
        int x=0;
        for(int i=0;i<n;i++) {
            if(used[i]) continue;
            if(x<(2*k)) {
                cout<<i<<" "<<n-(2*k)<<endl;
                used[i]=true;
                used[n-(2*k)]=true;
                x++;
            } else {
                cout<<i<<" "<<n-1-i<<endl;
                used[i]=true;
                used[n-1-i]=true;
            }
        }
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