/*
author:Karan
created:03.08.2021 11:14:58
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
    string s;
    cin>>s;
    bool same=true;
    for(int i=1;i<4;i++) {
        if(s[i]!=s[i-1]) {
            same=false;
            break;
        }
    }
    bool inc=true;
    for(int i=1;i<4;i++) {
        if((s[i]-'0')!=((s[i-1]-'0')+1)%10) {
            inc=false;
        }
    }
    if(inc||same) cout<<"Weak"<<endl;
    else cout<<"Strong"<<endl;
}