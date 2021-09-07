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
        vector<ll> arr(n);
        vector<ll> odd,even;
        for(ll i=0;i<n;i++) {
            cin>>arr[i];
            if(i%2) {
                odd.push_back(arr[i]);
            }
            else {
                even.push_back(arr[i]);
            }
        }
        
        vector<ll>sumodd,sumeven;
        sumodd.resize(odd.size());
        sumeven.resize(even.size());
        sumodd[0]=odd[0];
        sumeven[0]=even[0];
        for(ll i=1;i<odd.size();i++) {
            sumodd[i]=sumodd[i-1]+odd[i];
        }
        for(ll i=1;i<even.size();i++) {
            sumeven[i]=sumeven[i-1]+even[i];
        }
        vector<ll> minieven(even.size());
        vector<ll> miniodd(odd.size());
        minieven[0]=even[0];
        int mm=even[0];
        for(int i=1;i<even.size();i++) {
            if(even[i]<mm) {
                mm=even[i];
                minieven[i]=mm;
            }
            else{
                minieven[i]=mm;
            }
        }
        mm=odd[0];
        miniodd[0]=mm;
        for(int i=1;i<odd.size();i++) {
            if(odd[i]<mm) {
                mm=odd[i];
            }
            miniodd[i]=mm;
        }
        ll ans=(ll)1e15;
        for(ll i=2;i<=n;i++) {
            ll oddsize=i/2;
            ll evensize=(i+1)/2;
            ll finalsumodd=sumodd[oddsize-1];
            ll finalsumeven=sumeven[evensize-1];
            finalsumeven+=(minieven[evensize-1])*(n-evensize);
            finalsumodd+=(miniodd[oddsize-1])*(n-oddsize);
            ll temp=finalsumeven+finalsumodd;
            ans=min(ans,temp);
        }
        cout<<ans<<endl;
    }
}