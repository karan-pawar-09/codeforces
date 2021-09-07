/*
authot:Karan
created:21.05.2021 19:07:29
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll l=0;
    ll r=(ll)1e10;
    while(l+1<r) {
        ll m=(l+r)/2;
        if((m*(m+1))<=2*n) {
            l=m;
        }
        else {
            r=m;
        }
    }
    cout<<l<<endl;
    for(int i=1;i<l;i++) {
        cout<<i<<" ";
    }
    cout<<n-((l*(l-1))/2);
    cout<<endl;
}