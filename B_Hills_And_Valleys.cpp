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
        vector<int> ans(n);
        int an=0;
        for(int i=1;i<n-1;i++) {
            if(arr[i]>arr[i-1]&&arr[i]>arr[i+1]) {
                ans[i]=1;
                an++;
            }
            else if(arr[i]<arr[i-1]&&arr[i]<arr[i+1]) {
                ans[i]=-1;
                an++;
            }
            else {
                ans[i]=0;
            }
        }
        bool special=false;
        for(int i=0;i<n-2;i++) {
           if(ans[i]!=0&&ans[i+2]!=0&&ans[i+1]!=0) {               
                   special=true;
           }
        }
        
        if(special) {
            an-=3;
        }
        else {
            an-=2;
        }
        cout<<max(0,an)<<endl;
    }
}