#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string s;
    cin>>s;
    bool happy=true;
    for(int i=0;i<n;i++) {
        if(s[i]=='H') {
            happy=true;
        }
        else if(s[i]=='S') {
            happy=false;
        }
        else if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U') {
            happy=!happy;
        }
    }
    if(happy) {
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
}