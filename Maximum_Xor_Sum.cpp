/*
    author:Karan
    created:23.01.2023 13:02:02
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
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int ans = 0;
	for(int bit = 0; bit < 30; bit++){
		int andLast = n;
		for(int i = n - 1; i >= 0; i--){
			if((b[i] & (1 << bit)) == 0) break;
			andLast = i;
		}
		int orFirst = -1;
		for(int i = 0; i < n; i++){
			if(a[i] & (1 << bit)){
				orFirst = i;
				break;
			}
		}
		if(orFirst == -1) continue;
		else if(andLast == orFirst || orFirst + 2 == andLast){
			int cnt = n - andLast + (int) (orFirst + 2 == andLast);
			if(cnt % 2 == 1) ans += (1 << bit);
		}
		else ans += (1 << bit);
	}
	
	cout << ans << endl;
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