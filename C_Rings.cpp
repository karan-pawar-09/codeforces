/*
author:Karan
created:27.08.2021 13:18:35
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n;i++) {
        if(s[i]=='0') {
            if(i<(n/2)) {
                cout<<i+1<<" "<<n<<" "<<i+2<<" "<<n<<endl;
            }
            else {
                cout<<1<<" "<<i+1<<" "<<1<<" "<<i<<endl;
            }
            return;
        }
    }
    cout<<1<<" "<<n-1<<" "<<2<<" "<<n<<endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
}