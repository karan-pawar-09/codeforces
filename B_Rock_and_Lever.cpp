#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        int ans=0;
        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                if((arr[i]&arr[j])>=(arr[i]^arr[j]))
                ans++;
            }
        }
        cout<<ans<<endl;
         
    }
}