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
        ll n,k;
        cin>>n>>k;
        vector<ll> arr(n+1);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        arr[n]=-1;
        ll ans=-1;
        while(k>0) {
            k--;
            int i=0;
            while(i<n) {
                if(arr[i]<arr[i+1]) {
                    arr[i]++;
                    break;
                }
                i++;
            }
            if(i<n) {
                if(k==0) {
                    ans=i+1;
                    break;
                }                
            }
            else {
                break;
            }
        }
        cout<<ans<<endl;
    }
}
