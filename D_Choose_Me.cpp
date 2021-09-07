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
    vector<pair<ll,ll>> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i].second>>arr[i].first;
        arr[i].first+=2*arr[i].second;
    }
    sort(all(arr),greater<pair<ll,ll>>());
    ll aoki=0;
    for(int i=0;i<n;i++) {
        aoki+=arr[i].second;
    }
    int ans=0;
    ll takahashi=0;
    for(int i=0;i<n;i++) {
        takahashi+=arr[i].first;
        ans++;
        if(takahashi>aoki) {
            break;
        }
    }
    cout<<ans<<endl;
}