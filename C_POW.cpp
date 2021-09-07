/*
author:Karan
created:14.06.2021 12:45:48
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll a,b,c;
    cin>>a>>b>>c;
    if(c%2) {
        if(a>b) {
            cout<<">"<<endl;
        }
        else if(a<b) {
            cout<<"<"<<endl;
        }
        else {
            cout<<"="<<endl;
        }
    }   
    else {
        if(abs(a)>abs(b)) {
            cout<<">"<<endl;
        }
        else if(abs(a)<abs(b)) {
            cout<<"<"<<endl;
        }
        else {
            cout<<"="<<endl;
        }
    }
}