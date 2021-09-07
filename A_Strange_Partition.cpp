#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        ll n,x,a;
        cin>>n>>x;
        ll maxans=0;
        ll sum=0;
        for(ll i=0;i<n;i++) {
            cin>>a;
            sum+=a;
            maxans+=ceil((double)a/x);
        }
        ll minans=ceil((double)sum/x);
        cout<<minans<<" "<<maxans<<endl;
    }
}