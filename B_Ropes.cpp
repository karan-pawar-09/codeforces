#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

bool isTrue(double x,vector<ll> arr,double k) {
    ll n=arr.size();
    ll s=0;
    for(ll i=0;i<n;i++) {
        s+=arr[i]/x;
    }
    if(s>=k) {
        return true;
    }
    else {
        return false;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double n,k;
    cin>>n>>k;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    double  l=0;
    double  r=(double)1e8;
    for(int i=0;i<80;i++) {
        double m=l+(r-l)/2;
        if(isTrue(m,arr,k)) {
            l=m;
        }
        else {
            r=m;
        }
    }
    cout<<setprecision(20);
    cout<<l<<endl;
}