/*
    author:Karan
    created:24.06.2023 17:36:48
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

bool isPalindrome(string &s) {
    for(ll i = 0; i < (s.size()/2); i++) {
        if(s[i] != s[s.size() - 1 -i]) return false;
    }
    return true;
}
void solve() {
    ll n;
    cin >> n;
    vector<string> arr(n);
    for(ll i = 0; i < n;i++) {
        cin >> arr[i];
    }
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            if(i != j) {
                string temp = arr[i] + arr[j];
                if(isPalindrome(temp)) {
                    cout<<"Yes"<<endl;
                    return;
                }
            }
        }
    }
    cout<<"No"<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}