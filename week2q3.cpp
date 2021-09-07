/*
authot:Karan
created:18.05.2021 16:24:23
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

ll gcd(ll a,ll b) {
    if(b==0) {
        return a;
    }
    return gcd(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b;
    cin>>a>>b;
    cout<<gcd(a,b);
}