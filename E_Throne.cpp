#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--) {
        ll n,s,k;
        cin>>n>>s>>k;
        ll x,y;
        x=0,y=0;
        ll g=__gcd(n,k);
        if(s%g!=0) {
            cout<<"-1"<<endl;
        }
        else {
            k/=g;
            n/=g;
            s/=g;
            ll a=(-s+n)%n;
            ll kk=gcd(k,n,x,y);
            ll b=x;
            cout<<((a*(b%n))%n+n)%n<<endl;
        }
    }
}