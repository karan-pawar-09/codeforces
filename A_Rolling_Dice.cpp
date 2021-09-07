/*
author:Karan
created:04.07.2021 17:30:27
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
    if((6*a)>=b&&b>=a) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
}