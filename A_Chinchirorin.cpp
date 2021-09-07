/*
author:Karan
created:30.05.2021 20:15:33
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c;
    cin>>a>>b>>c;
    if(a==b) {
        cout<<c<<endl;
    }
    else if(b==c) {
        cout<<a<<endl;
    }
    else if(a==c) {
        cout<<b<<endl;
    }
    else {
        cout<<"0"<<endl;
    }
}