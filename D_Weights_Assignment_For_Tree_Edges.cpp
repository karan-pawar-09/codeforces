/*
    author:Karan
    created:25.11.2021 21:40:22
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
        int N; cin >> N;
        vector<int> b(N+10),q(N+10);
		for (int i = 1; i <= N; ++i) cin >> b[i];
		for (int i = 1; i <= N; ++i) { int p; cin >> p; q[p] = i; }
		for (int i = 1; i <= N; ++i) if (i != b[i] && q[i] < q[b[i]]) {
            cout<<-1<<endl;
            return;
        }	
        for (int i = 1; i <= N; ++i) cout << (q[i] - q[b[i]]) << " ";
        cout<<endl;
        
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}