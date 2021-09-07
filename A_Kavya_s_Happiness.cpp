//Karan Pawar
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<s.size();i++) {
        if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U') {
            ans++;
        }
    }
    if(ans%2) {
        cout<<"NO"<<endl;
    }
    else {
        cout<<"YES"<<endl;
    }
}