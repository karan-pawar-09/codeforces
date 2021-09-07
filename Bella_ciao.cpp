/*
author:Karan
created:04.06.2021 15:42:48
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
    int t;
    cin>>t;
    while(t--) {
        ll D,d,P,Q;
        cin>>D>>d>>P>>Q;
        ll n=(D/d);
        ll money=D*P;
        money+=d*(n*(n-1)/2)*Q+(D%d)*n*Q;      
        cout<<money<<endl;
    }   
}