/*
    author:Karan
    created:30.03.2022 16:49:47
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

int maxLenght(vector<int> a, vector<int> b) {
    int n = a.size();
    int m = b.size();
    int i = 0;
    int j = 0;
    int ans = 0;
    while (i < n and j < m) {
        if (a[i] == b[j]) {
            i++;
            j++;
            ans++;
        }
        else if (a[i] < b[j]) {
            i++;
            if (i < n) {
                a[i] += a[i - 1];
            }
        }
        else {
            j++;
            if (j < m) {
                b[j] += b[j - 1];
            }
        }
    }

    if (i >= n and j >= m) return ans;
    else return -1;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0;i < m;i++) {
        cin >> b[i];
    }
    cout << maxLenght(a, b) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t = 1;
    //cin>>t;
    while (t--) {
        solve();
    }
}