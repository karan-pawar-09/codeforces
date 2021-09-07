#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

bool isGood(ll m,ll number,ll k,ll sum) {
   return m*k>=100*number-sum*k;
} 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        ll n,k;
        cin>>n>>k;
        vector<ll> arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        ll sum=arr[0];
        ll maxi=0;
        for(int i=1;i<n;i++) {
            ll l=-1;
            ll r=(ll)1e15;
            while(r>l+1) {
                ll m=l+(r-l)/2;
                if(isGood(m,arr[i],k,sum)) {
                    r=m;
                }
                else {
                    l=m;
                }
            }
            sum+=arr[i];
            maxi=max(maxi,r);
        }
        cout<<maxi<<endl;
    }
}