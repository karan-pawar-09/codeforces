#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<ll>arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    ll sum=0;
    ll ans=0;
    for(int i=0;i<n;i++) {
        if(sum<=arr[i]) {
            sum+=arr[i];
            ans++;
        }
    }
    cout<<ans<<endl;
}