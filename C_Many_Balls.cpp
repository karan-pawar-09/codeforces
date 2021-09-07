/*
    author:Karan
    created:07.09.2021 18:01:04
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    ll n;
    cin>>n;
    string ans;
    while(n>=1) {
        if(n%2==0) {
            ans+="B";
            n/=2;
        }
        else {
            ans+="A";
            n--;
        }
    }
    reverse(all(ans));
    cout<<ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}