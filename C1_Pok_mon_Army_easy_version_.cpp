#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n,q;
        cin>>n>>q;
        vector<int> arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        int mx=arr[0];
        for(int i=0;i<n;i++) {
            int s=arr[i];
            int k=i%2;
            bool sign=true;
            int sum=0; 
            for(int j=i;j<n;j+=2) {                               
                if(sign==true) {                
                sum+=arr[j];
                sign=false;
                s=max(s,sum);
                }
                else{
                    sum-=arr[j];
                    sign=true;
                    s=max(s,sum);
                }
            }
            mx=max(mx,s);
        }
       cout<<mx<<endl;
    }
}