#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;
    cin>>s>>t;
        int j=0;
        int i=0;
        for(;j<t.size();) {
            for(;j<t.size();) {
                if(t[j]==s[i]) {
                    i++;
                    j++;
                    break;
                }
                else{
                    j++;
                }
            }
        }
    if(i==s.size()) {
        cout<<"true";
    }
    else {
        cout<<"false";
    }
}