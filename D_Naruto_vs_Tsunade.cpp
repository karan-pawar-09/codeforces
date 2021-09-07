#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n,q;
        cin>>n>>q;
        vector<ll>arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
           for(int i=0;i<n;i++) {
        }
        for(int i=0;i<q;i++) {
            ll l,r;
            cin>>l>>r;
            cout<<(upper_bound(arr.begin(),arr.end(),r)-arr.begin())-(lower_bound(arr.begin(),arr.end(),l)-arr.begin())<<endl;
        }
    }
}