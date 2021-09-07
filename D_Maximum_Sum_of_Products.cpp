/*
authot:Karan
created:18.05.2021 11:40:44
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

ll n;

bool isGood(ll a,ll b) {
    if(a>=0&&b<n) {
        return true;
    }
    else  {
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    cin>>n;
    vector<ll> a(n),b(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<n;i++) {
        cin>>b[i];
    }
    vector<ll> mul(n);
    ll multiplication=0;
    for(ll i=0;i<n;i++) {
        mul[i]=a[i]*b[i];
        multiplication+=mul[i];
    }
    ll ans=multiplication;
    for(ll i=1;i<n-1;i++) {
        ll temp=multiplication;
        for(ll k=0;k<=n/2;k++)  {
            if(isGood(i-k,i+k)) {
                temp-=mul[i-k];
                temp-=mul[i+k];
                temp+=a[i-k]*b[i+k];
                temp+=a[i+k]*b[i-k];
                ans=max(ans,temp);
            }
        }
    }
    for(ll i=0;i<n-1;i++) {
        ll temp=multiplication;
        for(ll k=0;k<n/2;k++) {
            if(isGood(i-k,i+1+k)) {
                temp-=mul[i-k];
                temp-=mul[i+1+k];
                temp+=a[i-k]*b[i+1+k];
                temp+=a[i+1+k]*b[i-k];
                ans=max(ans,temp);
            }
        }
    }
    cout<<ans<<endl;
}