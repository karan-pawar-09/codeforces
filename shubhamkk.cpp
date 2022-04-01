#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int inf = 1e9 + 10;
    vector<int> dp(200, inf);
    dp[n] = 0;
    for (int i = 0;i < 1000;i++) {
        for (int j = 0;j <= 150;j++) {
            if (j - 3 >=0) {
                dp[j - 3] = min(dp[j - 3], dp[j] + 1);
            }
            if (j + 2 <=150) {
                dp[j + 2] = min(dp[j + 2], dp[j] + 1);
            }
        }
    }
    cout << dp[m] << endl;
}

int32_t main() {

    solve();

}