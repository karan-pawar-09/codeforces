/*
author:Karan
created:03.08.2021 11:13:26
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
    int a,b;
    cin>>a>>b;
    if(a==0) {
        cout<<"Silver"<<endl;
    }
    else if(b==0) {
        cout<<"Gold"<<endl;
    }
    else {
        cout<<"Alloy"<<endl;
    }
}