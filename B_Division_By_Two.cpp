#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
ll answer(ll a) {
    ll ans=0;
    while(a&&a%2==0) {
        a/=2;
        ans++;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    vector<ll> ans(n);
    for(int i=0;i<n;i++) {
        ans[i]=answer(arr[i]);
    }
    cout<<*min_element(all(ans))<<endl;
}