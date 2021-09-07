/*
author:Karan
created:15.08.2021 20:25:39
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

bool better(string &a,string &b) {
    ll one=0;
    ll two=0;
    ll n=a.size();
    for(ll i=1;i<n;i++) {
        if(a[i]==a[i-1]) {
            one++;
        }
        if(b[i]==b[i-1]) {
            two++;
        }
    }
    return one<two;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        string str1="B";
        str1+=s;
        string str2="R";
        str2+=s;
        n=str1.size();
        for(ll i=0;i<n;i++) {
            if(i>0) {
                if(s[i-1]!='?') {
                    str1[i]=s[i-1];
                    str2[i]=s[i-1];
                }
                else {
                    if(str1[i-1]=='B') str1[i]='R';
                    else str1[i]='B';
                    if(str2[i-1]=='B') str2[i]='R';
                    else str2[i]='B';
                }
            }
            
        }
        better(str1,str2)?cout<<str1.substr(1)<<endl:cout<<str2.substr(1)<<endl;
    }
}