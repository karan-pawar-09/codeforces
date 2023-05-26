#include<bits/stdc++.h>
using namespace std;


bool isGood(string &s) {
    if(s.size()%2 == 0) {
        return false;
    }
    int count = -1;
    char c = s[s.size()/2];
    for(auto x: s) {
        if(x == c) {
            count++;
        }
    }
    int temp = 0;
    for(int i=0;i<s.size()/2;i++) {
        if(s[i] == c) {
            temp++;
        }
    }
    if(2*temp == count && count > 0) {
        return true;
    } else {
        return false;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<string> arr(n);
    int ans = 0;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        if(isGood(arr[i])) {
            ans++;
        }
    }
    cout<<ans<<endl;
}

int32_t main() {
    int t=1;
    while(t--) {
        solve();
    }
}