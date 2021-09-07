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
    while(t--) {
        ll a,b;
        cin>>a>>b;

        ll mini=(ll)1e10;

        for(ll i=b;i<b+70;i++) {
            ll ans=0;
            if(i==1) {
                i++;
            }
            ll k=a;
            while(k) {
                k/=i;
                ans++;
            }
            mini=min(mini,(i-b)+ans);
        }

        cout<<mini<<endl;
    }
}