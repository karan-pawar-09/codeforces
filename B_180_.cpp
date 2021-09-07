/*
author:Karan
created:24.05.2021 09:17:08
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
    for(int i=n-1;i>=0;i--) {
        if(s[i]=='6') {
            cout<<9;
        }
        else if(s[i]=='9') {
            cout<<6;
        }
        else {
            cout<<s[i];
        }
    }
}