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
    cout<<setprecision(6);
    cout<<fixed;
    while(t--) {
        int n;
        cin>>n;
        vector<ll> arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        long double ans=-(long double)1e10;
        for(int i=1;i<n;i++) {
            ans=max(ans,(long double)abs(arr[i]-arr[i-1]));
        }   
        cout<<ans<<'\n';
    }
}
