#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        int arr[n][m];
        int rows=0;
        int column=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin>>arr[i][j];
            }
        }
        for(int i=0;i<n;i++) {
            bool key=true;
            for(int j=0;j<m;j++) {
                if(arr[i][j]==1){
                    key=false;
                    break;
                }
            }
            if(key){
                rows++;
            }
        }
        for(int i=0;i<m;i++) {
            bool key=true;
            for(int j=0;j<n;j++) {
                if(arr[j][i]==1){
                    key=false;
                    break;
                }
            }
            if(key){
                column++;
            }
        }
        if((min(rows,column))%2) {
            cout<<"Ashish"<<endl;
        }
        else{
            cout<<"Vivek"<<endl;
        }
    }
}