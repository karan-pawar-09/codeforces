/*
    author:Karan
    created:04.03.2023 23:06:59
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
    int n = s.size();
    for(int i=0;i<(n/2);i++) {
        if(s[i] != s[n-1-i]) {
            return false;
        }
    }
    return true;
}
void solve() {
    int n;
    cin >> n;
    n = 2*n - 2;
    vector<string> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    sort(all(arr), [&](string a, string b) {
        return a.size() > b.size();
    });
    string a1 = arr[0];
    string a2 = arr[1];
    if(a1.size() == 1 ) {
        if(a1[0] == a2[0]) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
        return;
    }
    if(a1[0] == a2[1]) {
        string k = a2+a1;
        if(isPalindrome(k)) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    } else {
        string k = a1+a2;
        if(isPalindrome(k)) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}