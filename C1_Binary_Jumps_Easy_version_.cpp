/*
authot:Karan
created:17.05.2021 11:02:23
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
ll dist(ll n) {
    ll a=1;
    while(a<n) {
        a*=2;
    }
    ll b=a/2;
    return abs(n-a)<abs(n-b)?abs(n-a):abs(n-b);
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        n=abs(n);
        ll ans=0;
        while(n>0) {
            n=dist(n);
            ans++;
        }
        cout<<ans<<endl;
    }
}