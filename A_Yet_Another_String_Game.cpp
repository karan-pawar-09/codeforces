#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        for(int i=0;i<s.size();i++) {
            if(i%2==0) {
                if(s[i]!='a') {
                    s[i]='a';
                }
                else {
                    s[i]='b';
                }
            }
            else {
                if(s[i]!='z') {
                    s[i]='z';
                }
                else {
                    s[i]='y';
                }
            }
        }
        cout<<s<<endl;
    }
}