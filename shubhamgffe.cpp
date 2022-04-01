#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t;
    cin >> t;
    vector<int> chars(300, 0);
    vector<int> chart(300, 0);
    for (auto x : s) {
        chars[x]++;
    }
    for (auto x : t) {
        chart[x]++;
    }
    int one = 0;
    int two = 0;
    for (int i = 0;i < 300;i++) {
        if (chars[i] > chart[i]) {
            one += chars[i] - chart[i];
        }
        else if (chars[i] < chart[i]) {
            two += chart[i] - chars[i];
        }
    }
    if (one <= 1 and two <= 1) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int32_t main() {

    solve();

}