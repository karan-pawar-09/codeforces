#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        if (s.length() % 2 == 0 && s[0] != ')' && s.back() != '(') {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}