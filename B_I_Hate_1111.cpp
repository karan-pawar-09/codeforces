/*
author:Karan
created:28.05.2021 20:26:43
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
ll makeno(ll i) {
    string s;
    for(ll j=0;j<i;j++) {
        s+="1";
    }
    return stoi(s);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--) {
        ll x;
        cin>>x;
        bool ans=false;
        for(int i=0;i<11;i++) {
            if((x-i*111)%11==0&&(x-i*111)>=0) {
                ans=true;
            }
        }    
        if(ans) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }       
        
    }
}