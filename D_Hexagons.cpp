#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int x,y;
        cin>>x>>y;
        long long c1, c2, c3, c4, c5, c6;
        cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;
		long long rlt = LLONG_MAX;
        ll  ans;
        if (x >= 0) {
			ans = c6 * x + ((y >= 0) ? c2 * y : c5 * -y);
			rlt = min(rlt, ans);
			ans = c1 * x + ((y >= x) ? c2 * (y - x) : c5 * (x - y));
			rlt = min(rlt, ans);
		}
		else {
			ans = c3 * -x + ((y >= 0) ? c2 * y : c5 * -y);
			rlt = min(rlt, ans);
			ans = c4 * -x + ((y >= x) ? c2 * (y - x) : c5 * (x - y));
			rlt = min(rlt, ans);
		}
		if (y >= 0) {
			ans = c2 * y + ((x >= 0) ? c6 * x : c3 * -x);
			rlt = min(rlt, ans);
			ans = c1 * y + ((x >= y) ? c6 * (x - y) : c3 * (y - x));
			rlt = min(rlt, ans);
		}
		else {
			ans = c5 * -y + ((x >= 0) ? c6 * x : c3 * -x);
			rlt = min(rlt, ans);
			ans = c4 * -y + ((x >= y) ? c6 * (x - y) : c3 * (y - x));
			rlt = min(rlt, ans);
		}
		cout << rlt << endl;
    }
}
