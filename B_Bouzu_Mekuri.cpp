/*
author:Karan
created:17.07.2021 17:33:06
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
    cin>>s;
    int i=0;
    for(i=0;i<n;i++) {
        if(s[i]=='1') {
            break;
        }
    }
    if(i%2==0) {
        cout<<"Takahashi"<<endl;
    }
    else {
        cout<<"Aoki"<<endl;
    }
}