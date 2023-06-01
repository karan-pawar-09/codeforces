
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'


bool checkSuffix(string a, string b, int k) { 
    for(auto x: a) {
        if(x-'0' > k) return false;
    }
    return (a.substr(a.size()-b.size()) == b);
}
void solve() {
    ll n, d, s;
    cin >> n >> d >> s;
    int k = to_string(n).size();
    int p = to_string(s).size();
    for(int i=)
    int count = 0;
    for(ll i=s;i<=n;i++) {
        if(checkSuffix(to_string(i), to_string(s), d)) {
            count++;
            cout<<i<<endl;
        }
    }
    cout<<count<<endl;
}

int32_t main() {
    ll t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}