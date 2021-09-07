#include<bits/stdc++.h>
using namespace std;
#define ll long long

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
        ll length=0;
        ll ans=0;
        for(int i=1;i<n;i++) {
            if(arr[i]>=arr[i-1]) {
                length++;
            }
            else{
                ans+=(length*(length+1))/2;
                length=0;
            }
        }
        ans+=(length*(length+1))/2;
        cout<<ans<<endl;
    }
}