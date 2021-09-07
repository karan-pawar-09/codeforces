#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

ll count(vector<ll> x) {
    sort(x.begin(), x.end());
    return x[x.size() / 2] - x[(x.size() - 1) / 2] + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> x(n), y(n);
        for (ll i = 0; i < n; ++i) {
            cin >> x[i] >> y[i];
        }
        cout << count(x) * count(y) << '\n';
    }
}