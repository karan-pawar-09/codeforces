#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ll k=(ll)1e9;
    int k=10000007;
    vector<bool> is_prime(k+1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= k; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= k; j += i)
                is_prime[j] = false;
        }
    }
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        vector<ll> b(n);
        for(ll i=0;i<n;i++) {
            cin>>b[i];
        }
        vector<ll> a(n,1);
        ll p=2;
        vector<bool> truth(n,true);
        ll aa=0;
        for(int i=0;aa<n;i++) {
            if(is_prime[i]==true) {
                a[aa]=i;
                aa++;
            }
        }
        for(int i=0;i<n;i++) {
            if(b[i]!=i+1) {
                a[i]=p;
                p++;
                if(a[b[i]-1]%a[i]!=0) {
                    if(truth[b[i]-1]) {
                        a[b[i]-1]=2;
                        truth[b[i]-1]=false;
                    }
                    a[b[i]-1]*=a[i];
                }
            }
        }
        for(int i=0;i<n;i++) {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}