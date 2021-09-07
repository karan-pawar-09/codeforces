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
        bool ans=false;
        int answer=0;
        for(int i=0;i<n-1;i++) {
            if(arr[i]!=arr[i+1]) {
                ans=true;
               int temp;
               arr[i]>arr[i+1]?temp=i:temp=i+1;
                arr[answer]>arr[temp]?answer=answer:answer=temp;
            }
        }
        if(ans)
        cout<<answer+1<<endl;
        else
        {
            cout<<"-1"<<endl;
        }
        
    }
}