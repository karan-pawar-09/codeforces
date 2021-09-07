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
        int start=0;
        int end=n-1;
        for(int i=0;i<n;i++) {
            if(arr[i]==1) {
                start=i;
                break;
            } 
        }
        for(int i=n-1;i>=0;i--) {
            if(arr[i]==1) {
                end=i;
                break;
            }
        }
        for(int i=start;i<end;i++) {
            if(arr[i]==0) {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}