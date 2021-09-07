/*
author:Karan
created:31.05.2021 20:11:05
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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        ll ans=0;
        for(int i=0;i<n-1;i++) {
            if(s[i]!=s[i+1]) {
                ans+=1;
            }
            else {
                ans+=2;
            }
        }
        while(k--) {
            int q;
            cin>>q;
            int minus=0;
            int plus=0;
            q--;
            if(q==0) {
                if(s[q]==s[q+1]) {
                    minus=2;
                }
                else {
                    minus=1;
                }
            }
            else if(q==n-1) {
                if(s[q]==s[q-1]) {
                    minus=2;
                }
                else {
                    minus=1;
                }
            }
            else {
                if(s[q]==s[q-1]) {
                    minus+=2;
                }
                else {
                    minus+=1;
                }
                if(s[q]==s[q+1]) {
                    minus+=2;
                }
                else {
                    minus+=1;
                }
            }
            if(s[q]=='0') {
                s[q]='1';
            }
            else {
                s[q]='0';
            }
            if(q==0) {
                if(s[q]==s[q+1]) {
                    plus=2;
                }
                else {
                    plus=1;
                }
            }
            else if(q==n-1) {
                if(s[q]==s[q-1]) {
                    plus=2;
                }
                else {
                    plus=1;
                }
            }
            else {
                if(s[q]==s[q-1]) {
                    plus+=2;
                }
                else {
                    plus+=1;
                }
                if(s[q]==s[q+1]) {
                    plus+=2;
                }
                else {
                    plus+=1;
                }
            }
            ans=ans+plus-minus;
            cout<<ans<<endl;
        }
    }
}