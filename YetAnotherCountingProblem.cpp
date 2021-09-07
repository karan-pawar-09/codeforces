#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int a,b,q;
        cin>>a>>b>>q;
        int count=0;
        int arr[q][2];
        for(int i=0;i<q;i++) {
            cin>>arr[i][0]>>arr[i][1];
        }
        for(int i=0;i<q;i++) {
            for(int j=arr[i][0];j<=arr[i][1];j++) {
                int z=j%a;
                int zz=z%b;
                int w=j%b;
                int ww=w%a;
                if(zz!=ww) {
                    count++;
                }
               
            }
            cout<<count<<" ";
            count=0;
        }
        cout<<endl;
    }
}