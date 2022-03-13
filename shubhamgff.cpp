/*
    author:Karan
    created:12.03.2022 22:15:22
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

vector<ll> getFinalElement(vector<ll> arr) {
    stack<ll> s;
    ll n = arr.size();
    for (ll i = 0;i < n;i++) {
        if (arr[i] > 0) {
            s.push(arr[i]);
        }
        else {
            while (s.size() and s.top() < abs(arr[i]) and s.top() >= 0) {
                s.pop();
            }
            if (s.size() and s.top() == abs(arr[i])) s.pop();
            else if (s.size() == 0 or (s.size() and s.top() < 0)) {
                s.push(arr[i]);
            }
        }
    }
    vector<ll> ans;
    while (s.size()) {
        ans.push_back(s.top());
        s.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void solve() {
    ll n;
    cin >> n;

    vector<ll> arr(n);
    for (ll i = 0;i < n;i++) {
        cin >> arr[i];
    }
    vector<ll> ans = getFinalElement(arr);
    for (auto x : ans) cout << x << " ";
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t = 1;
    //cin>>t;
    while (t--) {
        solve();
    }
}