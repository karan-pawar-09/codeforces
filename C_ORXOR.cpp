#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
	int n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    ll ans=(ll)1e18+7;
    for(ll no=0;no<(1<<(n-1));no++) {
        ll OR=0;
        ll XOR=0;
        for(int j=0;j<n;j++) {
            OR|=arr[j];
            if(no&(1<<j)) {
                XOR^=OR;
                OR=0;
            }
        }
        XOR^=OR;
        ans=min(XOR,ans);
    }
    cout<<ans<<endl;
}
