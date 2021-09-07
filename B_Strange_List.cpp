#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll highestPowerof2(ll n,ll x) { 
    int ans=0;
    while(n%x==0) {
        n/=x;
        ans++;
    }
    return ans+1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        ll n,x;
        cin>>n>>x;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++) {
            cin>>arr[i];
        }
        int min= highestPowerof2(arr[0],x);
        int minindex=0;
        for(int i=1;i<n;i++) {
            if(highestPowerof2(arr[i],x)<min) {
                min=highestPowerof2(arr[i],x);
                minindex=i;
            }
        }
        ll sum=0;
        for(int i=0;i<n;i++) {
            sum+=min*arr[i];
        }
        for(int i=0;i<minindex;i++) {
            sum+=arr[i];
        }
        cout<<sum<<endl;
    }
}