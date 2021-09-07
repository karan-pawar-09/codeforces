/*
authot:Karan
created:17.05.2021 21:46:42
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(), ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll q;
    cin >> q;
    while (q--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
            --arr[i];
        }
        sort(all(arr));
        ll z = 2 * n - 1;
        vector<vector<ll>> dp(n + 1, vector<ll>(z + 1, (ll)1e9));
        dp[0][0] = 0;
        for (ll i = 0; i <= n; i++) {
            for (ll j = 0; j < z; j++) {
                if (dp[i][j] < (ll)1e9) {
                    if (i < n) {
                        dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(arr[i] - j));
                    }
                    dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
                }
            }
        }
       
        cout << dp[n][z] << endl;
    }
}