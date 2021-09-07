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
        vector<int>arr(n);
        int sum=0;
        bool two=true;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            if(arr[i]==1) {
                two=false;
            }
            sum+=arr[i];
        }
        if(sum%2==0) {
            if(two) {
                if(n%2) {
                    cout<<"NO"<<endl;
                }
                else {
                    cout<<"YES"<<endl;
                }
            }
            else {
                cout<<"YES"<<endl;
            }
        }
        else {
            cout<<"NO"<<endl;
        }
    }
}   