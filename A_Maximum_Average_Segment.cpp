#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
pair<ll,ll>answer;
bool isGood(vector<ll>arr,ll n,ll d,ll x) {
    for(ll i=0;i<n;i++) {
        arr[i]-=x;
    }
    vector<ll>p(n);
    p[0]=arr[0];
    for(ll i=1;i<n;i++) {
        p[i]+=p[i-1]+arr[i];
    }
    vector<ll>mini(n);
    vector<ll>l(n);
    l[0]=0;
    mini[0]=p[0];
    for(ll i=1;i<n;i++) {
        if(p[i]<mini[i-1]) {
            mini[i]=p[i];
            l[i]=i;
        }
        else {
            mini[i]=mini[i-1];
            l[i]=l[i-1];
        }
    }
    bool ans=false;
    for(ll i=d;i<n;i++) {
        if(p[i]>=mini[i-d]) {
            ans=true;
        }
        if(ans=true) {
            answer={l[i-d],i};
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll d,n;
    cin>>n>>d;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    ll l=0;
    ll r=(ll)1e15;
    while(r>l+1) {
        ll x=l+(r-l)/2;
        if(isGood(arr,n,d,x)) {
            l=x;
        }
        else {
            r=x;
        }
    }
    cout<<answer.first<<" "<<answer.second<<endl;
}