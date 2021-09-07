#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    ll ans=(ll)1e10+7;
    ll w1=0;
    ll w2=0;
    vector<ll> sum(n);
    sum[0]=arr[0];
    for(int i=1;i<n;i++) {
        sum[i]=sum[i-1]+arr[i];
    }
    for(int i=0;i<n-1;i++) {
        w1=0;
        w2=0;
        w1=sum[i];
        w2=sum[n-1]-sum[i];
        ans=min(ans,abs(w1-w2));
    }
    cout<<ans<<endl;
}