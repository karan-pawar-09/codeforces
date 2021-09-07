#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;
    cin>>s>>t;
    int s1=0;
    int s2=0;
    for(int i=0;i<s.size();i++) {
        s1+=s[i]-'0';
    }
    for(int i=0;i<s.size();i++) {
        s2+=t[i]-'0';
    }
    s1>=s2?cout<<s1:cout<<s2<<endl;
}