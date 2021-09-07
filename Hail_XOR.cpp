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
        int x;
        cin>>x;
        vector<int> arr(n);
        if(2*x>=n) {
            for(int i=0;i<n;i++) {
                cout<<"0"<<" ";
            }
        }
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        if(x==1) {
            arr[0]=0;
        }  
        else {
            arr[0]=0;
            arr[1]=0;
        }          
        for(int i=0;i<n;i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}