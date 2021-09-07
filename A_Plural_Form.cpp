#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    if(s[s.size()-1]=='s') {
        cout<<s<<"es"<<endl;
    }
    else {
        cout<<s<<"s"<<endl;
    }
}