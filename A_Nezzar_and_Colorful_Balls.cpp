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
        vector<int> arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        int ans=1;
        int temp=1;
        for(int i=1;i<n;i++) {
            if(arr[i]==arr[i-1]) {
                temp++;
                ans=max(ans,temp);
            }
            else {
                ans=max(ans,temp);
                temp=1;
            }
        }
        cout<<ans<<endl;
    }
}