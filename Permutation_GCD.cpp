/*
    author:Karan
    created:03.08.2022 20:36:37
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
    int n,x;
    cin>>n>>x;
    if(x<n) cout<<-1<<endl;
	else {
	    cout<<x-n+1<<" ";
	    for(int i=1;i<=n;i++) {
	        if(i!=x-n+1) {
	            cout<<i<<" ";
	        }
	    }
	    cout<<endl;
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