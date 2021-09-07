
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
        ll n;
        cin>>n;
        string s=to_string(n);
        ll answer=0;
        for(ll i=0;i<s.size();i++) {
            answer=max(answer,(ll)(s[i]-'0'));
        }
        cout<<answer<<endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        solve();
    }
}