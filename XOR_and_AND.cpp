
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t = 1;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (ll i = 0;i < n;i++) {
            cin >> arr[i];
        }
        vector<ll> temp(n, 0);
        ll res = 0;
        for (ll i = 0;i < n;i++) {
            for (ll j = 0;j < 32;j++) {
                if (arr[i] & (1 << j)) {
                    temp[i] = max(temp[i], j);
                }
            }
        }
        vector<ll> ppre(40, 0);
        for (auto x : temp) {
            ppre[x]++;
        }
        for (auto x : ppre) {
            res += ((x) * (x - 1)) / 2;
        }
        cout << res << endl;
    }
}