#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        int even=0;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            if(arr[i]%2==0) {
                even++;
            }
        }
        
        if(even%2==0) {
            cout<<"YES"<<endl;
        }
        else{
            sort(arr.begin(),arr.end());
            bool flag=false;
            for(int i=1;i<n;i++) {
                if((arr[i]%2!=arr[i-1]%2)&&(arr[i]-arr[i-1]==1)){
                    flag=true;
                    break;
                }
                else{
                    continue;
                }
            }
            if(flag) {
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
}