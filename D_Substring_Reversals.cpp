#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        ll n=s.size();
        vector<ll> arr(27,0);
        ll ans=n*(n-1)/2;
        for(ll i=0;i<n;i++) {
            arr[s[i]-'a']++;
        }
        for(ll i=0;i<27;i++) {
            ans-=arr[i]*(arr[i]-1)/2;
        }
        cout<<++ans<<endl;
    }
}