#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        int min=arr[1]-arr[0];
        for(int i=2;i<n;i++) {
            if((arr[i]-arr[i-1])<min) {
                min=arr[i]-arr[i-1];
            }
        }
        cout<<min<<endl;
    }
}