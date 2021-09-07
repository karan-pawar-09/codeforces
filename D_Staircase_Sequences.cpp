#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

bool isGood(ll N,ll n) {
    ll ans=false;
    ll sum=N-n*(n-1)/2;
    if(sum%n==0) {
        ans=true;
    }
    ll a=sum/n;
    if(a>=1-N&&a<=N&&ans) {
        return true;
    }
    else {
        return false;
    }
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin>>N;
    ll k=0;
    for(ll i=1;i*i<=N*2;i++) {
        if(isGood(N,i)) {
            k++;
        }
    }
    cout<<k*2<<endl;
}