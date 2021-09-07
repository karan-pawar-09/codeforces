#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x;
    cin>>n>>x;
    ll a=n;
    int p=x;
    int ans=0;
    while(n/x) {
        ans+=n/x;
        x=x*p;
    }
    if(n==x) {
        ans++;
    }
    cout<<ans<<endl;
}