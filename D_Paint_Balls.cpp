#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<ll> arr(m+2,0);
    arr[m+1]=n+1;
    for(ll i=1;i<=m;i++) {
        cin>>arr[i];
    }
    sort(all(arr));
    // ll mini=(ll)1e18;
    vector<ll> mini(m+1,(ll)1e18);
    mini[0]=arr[1]-arr[0];
    for(ll i=2;i<=m+1;i++) {
        mini[i-1]=(arr[i]-arr[i-1]);       
    }
    ll ans=0;
    if(*max_element(all(mini))==1) {
        ans=0;
        cout<<ans<<endl;
        return 0;
    }
    else {
        vector<ll> k;
        for(int i=0;i<m+1;i++) {
            if(mini[i]!=1) {
                k.push_back(mini[i]);
            }
        }
        ll diff=*min_element(all(k))-1;        
        ll ans=0;
        for(int i=1;i<=m+1;i++) {
            if((arr[i]-arr[i-1]-1)%diff==0) {
                ans+=(arr[i]-arr[i-1]-1)/diff;
            }
            else {
                ans+=((arr[i]-arr[i-1]-1)/diff)+1;
            }
        }        
        cout<<ans<<endl;

    }
}