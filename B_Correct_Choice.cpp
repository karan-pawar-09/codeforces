#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<ll> arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        ll max=-(ll)1e10;
        ll ans=0;
        for(int k=n;k>=1;k--) {
            ll temp=0;
            for(int i=k-1;i<n;i+=k) {
                temp+=arr[i];
            }
            if(temp>=max) {
                max=temp;
                ans=k;
            }
        }
        cout<<ans<<endl;;

    }
}