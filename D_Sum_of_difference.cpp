#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    ll ans=0;
    for(int i=0;i<n;i++) {
        ans+=i*arr[i]-(n-1-i)*arr[i];
    }
    cout<<ans;
}