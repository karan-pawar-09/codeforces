/*
authot:Karan
created:17.05.2021 14:42:27
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        vector<ll> b(n);
        for(ll i=0;i<n;i++) {
            cin>>b[i];
        }
        bool ans=true;
        if(b[0]%2==1) {
            ans=false;
            cout<<"-1";
        }
        else {
            vector<ll> arr(n);
            arr[0]=b[0]/2;
            ll sum=arr[0];
            for(ll i=1;i<n;i++) {
                ll x=b[i]-sum-b[i-1];
                if(x%(i+2)!=0||x<=0) {
                    ans=false;
                    break;
                }
                else {
                    arr[i]=x/(i+2);
                }
                sum+=arr[i];
                // sum+=b[i];
            }
            if(ans)
            for(ll i=0;i<n;i++) {
                cout<<arr[i]<<" ";
            }
            else {
                cout<<"-1";
            }
        }
        cout<<endl;
    }
}
                         