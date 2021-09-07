/*
author:Karan
created:06.09.2021 01:30:56
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    ll s,n;
    cin>>s>>n;
    while (n > 1) {
		ll r = 1e18;		
		while (s - r < (n-1)) {
			r /= 10;
		}
		
		cout << r << " ";
		s -= r;
		--n;
	}
	
	if (n == 1) cout << s;
	
	cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        solve();
    }
}