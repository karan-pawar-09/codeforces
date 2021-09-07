#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    bool ans=false;

    if(s[0]==s[1]&&s[1]==s[2]||s[1]==s[2]&&s[2]==s[3]) {
        ans=true;
    }
    if(ans) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
}   