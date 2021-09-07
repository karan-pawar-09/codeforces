#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

typedef long long li;
typedef long double ld;
typedef pair<li, li> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

int n;
vector<li> a;

inline bool read() {
	if(!(cin >> n))
		return false;
	a.resize(n);
	fore (i, 0, n)
		cin >> a[i];
	return true;
}

li d(const pt &a, const pt &b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

inline void solve() {
	li ans = 0;
	
    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
			if (i + 2 <= j) {
				bool ok = true;
                for(int i1=i;i1<j;i1++) {
                         for(int i2=i1+1;i2<j;i2++) {
                            if (d(pt(a[i1], i1), pt(a[j], j)) == d(pt(a[i1], i1), pt(a[i2], i2)) + d(pt(a[i2], i2), pt(a[j], j)))
                                ok = false;
                     }
				}
				if (!ok) break;
			}
			ans++;
		}
	}
	cout << ans << endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);

	int t; cin >> t;
	
	while(t--) {
		read();
		solve();
	}
	return 0;
}