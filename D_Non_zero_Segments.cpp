#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans(vector<ll> arr) {
    ll n=arr.size();
    ll answer=0;
    for(ll i=0;i<n;i++) {
        ll temp=0;
        for(ll j=i;j<n;j++) {
            temp+=arr[j];
        }
        if(temp==0){
            answer++;
        }
    }
    return answer;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<ll> arr(n,0);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    ll answ=ans(arr);
    cout<<answ<<endl;
}