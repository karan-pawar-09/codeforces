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
        int flag=1;
        for(int i=1;i<n;i++) {
            if(((arr[i]==(arr[i-1])+1))||(arr[i]<arr[i-1])) {
                flag=1;
            }
            else { 
                flag=0;
                break;
            }
        }
        if(flag==1) {
            cout<<"Yes"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
}