/*
author:Karan
created:31.05.2021 20:01:42
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        int steps=abs(c-a)+abs(b-d);
        if(steps<=k) {
            if((k-steps)%2==0)
            cout<<"YES"<<endl;
            else {
                cout<<"NO"<<endl;
            }
        }
        else {
            cout<<"NO"<<endl;
        }
    }
}