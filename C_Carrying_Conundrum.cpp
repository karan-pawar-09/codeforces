/*
author:Karan
created:05.09.2021 20:49:05
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'


void solve() {
    int n;
    cin>>n;
    string str=to_string(n);
    string str1,str2;
    for(int i=0;i<str.size();i+=2) {
        str1.push_back(str[i]);
    }
    for(int i=1;i<str.size();i+=2) {
        str2.push_back(str[i]);
    }
    int no1=0;
    if(str1.size()) {
        no1=stoll(str1);
    }
    int no2=0;
    if(str2.size()) {
        no2=stoll(str2);
    }
    
    cout<<(no1+1)*(no2+1)-2<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
}