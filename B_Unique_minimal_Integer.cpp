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
        int n;
        cin>>n;
        vector<ll> arr(n);
        vector<ll> freq(n+1,0);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            freq[arr[i]]++;
        }
        int ans=-1;
        int mini=(int)1e6+7;
        for(int i=0;i<n;i++) {
            if(freq[arr[i]]==1) {
                if(arr[i]<=mini) {
                    mini=arr[i];
                    ans=i+1;
                }
            }
        }
        cout<<ans<<endl;
    }
}