#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int arr[n];
        int pos=0;
        int ans;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            if(arr[i]%2==0) {
                pos++;
                ans=i+1;
            }
        }
        if(pos) {
            cout<<"1"<<endl<<ans<<endl;
        }
        else {
            if(n>=2) {
                cout<<"2"<<endl<<"1"<<" "<<"2"<<endl;
            }
            else{
                cout<<"-1"<<endl;
            }
        }
    }
}