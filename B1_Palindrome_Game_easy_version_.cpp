/*
authot:Karan
created:20.05.2021 20:27:38
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll zeros=0;
        for(ll i=0;i<n;i++) {
            if(s[i]=='0') {
                zeros++;
            }
        }
        
        if(zeros>1&&n%2==1&&s[n/2]=='0') {
            cout<<"ALICE"<<endl;
        }
        else {
            cout<<"BOB"<<endl;
        }
    }
}