#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int gcd(int a,int b) {
    b?gcd(b,a%b):a;
}
int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int gCd;
    if(n==1) {
        gCd=arr[0];
    }
    else{
        gCd=gcd(arr[0],arr[1]);
        for(int i=2;i<n;i++) {
            gCd=gcd(gCd,arr[i]);
        }
    }
    long long mul=1;
    for(int i=0;i<n;i++) {
        mul=((mul%mod)*(arr[i]%mod))%mod;
    }
    long long T=mul;
    for(int i=0;i<gCd-1;i++) {
        mul=((mul%mod)*(T%mod))%mod;
    }
    cout<<mul;
}