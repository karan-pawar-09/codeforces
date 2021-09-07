#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<ll> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    ll ans=(ll)0;
    sort(all(arr));
    for(int i=k-1;i<n;i++) {
        ll med=arr[i-k/2];
        ans=max(ans,med);
    }
    cout<<ans<<endl;
}