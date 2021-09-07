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
        vector<ll> arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        vector<bool> isSelected(n,false);
        int maxi=0;
        for(int i=0;i<n;i++) {
            int j=i;
            int tempsum=0;
            if(!isSelected[j]) {
                while(j<n) {
                    if(isSelected[j]) {
                        break;
                    }
                    tempsum+=arr[j];
                    isSelected[j]=true;
                    j+=arr[j];                
                }
            }
            maxi=max(maxi,tempsum);
        }
        cout<<maxi<<endl;
    }
}