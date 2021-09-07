/*
author:Karan
created:19.06.2021 17:59:04
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
    ll a,b;
    cin>>a>>b;
    ll ans=0;
    for(ll i=a;i<=b;i++) {
        if(i==1) {
            i++;
        }
        ll temp=0;
        for(ll j=i;j<=b;j+=i) {
            temp++;
        }
        ans+=temp*(temp-1);
    }
    ll calc=0;
    for(ll i=2;i<b;i++) {
        ll k=a%i;
        ll temp=0;
        for(ll j=k+a;j<=b;j+=i) {
            temp++;
        }
        calc+=temp*(temp-1);
    }
    cout<<calc-ans<<endl;
}