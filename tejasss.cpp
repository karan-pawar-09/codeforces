/*
author:Karan
created:23.08.2021 17:32:59
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++) {
        s.push_back('0'+i);
    }
    for(int i=n;i>=1;i--) {
        s.push_back('0'+i);
    }
    cout<<s<<endl;
    for(int i=n-1;i>=1;i--) {
        s[i]=s[s.size()-1-i]='*';
        cout<<s<<endl;
    }
}