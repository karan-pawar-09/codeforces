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
    ll ans=(ll)1e18;
    if(n==1) {
        cout<<arr[0]<<endl;
        return 0;
    }
    else {
    for(int i=k-1;i<n;i++) {
        if(arr[i-k+1]*arr[i]<0) {
            ans=min(ans,abs(arr[i-k+1])+abs(arr[i])+min(abs(arr[i]),abs(arr[i-k+1])));
        }
        else  {
            ans=min(ans,max(abs(arr[i-k+1]),abs(arr[i])));
        }
    }
    cout<<abs(ans)<<endl;
    }
}