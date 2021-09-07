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
        set<int> ans;
        for(int i=1;i<n;i++) {
            ans.insert(arr[i]-arr[i-1]);
        }
        
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                ans.insert(arr[j]-arr[i]);
            }
        }
        cout<<ans.size()<<endl;
    }
}