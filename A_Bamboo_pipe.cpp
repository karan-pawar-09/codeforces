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
    sort(all(arr));
    ll t=0;
    ll sum=0;
    for(int i=n-1;i>=0&&t<k;i--) {
        sum+=arr[i];
        t++;
    }
    
    cout<<sum<<endl;
}