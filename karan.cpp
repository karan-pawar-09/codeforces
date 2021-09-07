#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int n;
    cin>>s>>n;
    cout<<s[s.size()-1]%n;
}