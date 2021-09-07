/*
author:Karan
created:06.06.2021 22:15:11
*/
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
    int n=s.size();
    ll ans=1;
    ll temp=1;
    for(int i=1;i<n;i++) {
        if(s[i]==s[i-1]) {
            temp++;
        }
        if(s[i]!=s[i-1]||i==(n-1)) {
            ans=max(temp,ans);
            temp=1;            
        }
    }
    cout<<ans<<endl;
}       