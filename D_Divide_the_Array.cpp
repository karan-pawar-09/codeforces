#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++) {
            cin>>arr[i];
        }
        ll mini=(ll)1e18+7;
        ll x=0;
        for(int i=0;i<n-1;i++) {
            if(abs(arr[i]-arr[i+1])<mini) {
                mini=abs(arr[i]-arr[i+1]);
                x=i;
            }
        }
        mini=(ll)1e18+7;
        ll y=0;
        for(int i=0;i<n-1;i++) {
            if(i!=x) {
                if(abs(arr[i]-arr[i+1])<mini) {
                    mini=abs(arr[i]-arr[i+1]);
                    y=i;
                }
            }
        }
        vector<ll>p;
        vector<ll>q;
        vector<ll>r;
        for(int i=0;i<=min(x,y);i++) {
            p.push_back(arr[i]);
        }
        for(int i=min(x,y)+1;i<=max(x,y);i++){
            q.push_back(arr[i]);
        }
        for(int i=max(x,y)+1;i<n;i++) {
            r.push_back(arr[i]);
        }
        cout<<abs(*max_element(p.begin(),p.end())-*min_element(p.begin(),p.end()))+abs(*max_element(q.begin(),q.end())-*min_element(q.begin(),q.end()))+abs(*max_element(r.begin(),r.end())-*min_element(r.begin(),r.end()))<<endl;
    }
}