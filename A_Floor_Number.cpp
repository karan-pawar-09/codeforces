#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--) {
        ll n,x;
        cin>>n>>x;
        ll ans=2;
        ll floor=1;
        if(n<=ans) {
            cout<<floor<<endl;
        }
        else{
            while(ans<n) {
                ans+=x;
                floor++;
            }
            cout<<floor<<endl;
        }
    }
}