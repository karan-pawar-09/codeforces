/*
author:Karan
created:13.06.2021 14:56:17
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        string s,t;
        cin>>s>>t;
        bool ans=true;        
        int i=0;
        int j=0;
        for(i,j;i<t.size();i++,j++) {
            if(j>=s.size()) {
                ans=false;
                break;
            }
            if(t[i]=='B'&&s[j]!='B') {
                j--;
            }
            if(s[j]!=t[i]&&t[i]!='B') {
                while(s[j]=='A'&&t[i]!='B') {
                    i--;
                }
            }
            else {
                if(t[i]!='B') {
                    if(s[j]!=t[i])
                        ans=false;
                }
            }
        }
        for(j;j<s.size();j++) {
            if(s[j]!='A') {
                ans=false;
            }
        }       
        ans?cout<<"YES"<<endl:cout<<"NO"<<endl;
    }   
}