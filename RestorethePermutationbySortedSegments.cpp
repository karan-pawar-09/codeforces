#include<bits/stdc++.h>
using namespace std; 
//kaaaaaa
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n-1);
        
        for(int i=0;i<n-1;i++) {
            int a;
            cin>>a;
            arr[i].push_back(a);
            for(int j=0;j<a;j++) {
                int k;
                cin>>k;
                arr[i].push_back(k);
            }
        }
        int max=arr[0][arr[0][0]];
        int min = arr[0][1];
        for(int i=1;i<n-1;i++) {
            if(arr[i][1]<min) {
                min=arr[i][1];
            }
            if(arr[i][arr[i][0]]>max) {
                max=arr[i][arr[i][0]];
            }
        }
        for(int i=min;i<=max;i++) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}