/*
author:Karan
created:30.05.2021 17:06:31
*/
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
        int k;
        cin>>k;
        bool ans=true;
        while(k--) {
            string s;
            cin>>s;            
            if(s[0]>=97) {
                for(int i=0;i<s.size();i++) {
                    if(s[i]>'m') {
                        ans=false;
                    }
                    if(s[i]<'a') {
                        ans=false;
                    }
                }
            }
            else {
                for(int i=0;i<s.size();i++) {
                    if(s[i]<'N') {
                        ans=false;
                    }
                    if(s[i]>'Z') {
                        ans=false;
                    }
                }
            }
        }
        ans?cout<<"YES"<<endl:cout<<"NO"<<endl;
    }
}