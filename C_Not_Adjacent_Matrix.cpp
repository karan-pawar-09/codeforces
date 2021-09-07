#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n,vector<int> (n));
        if(n==1) {
            cout<<"1"<<endl;
        }
        else if(n==2) {
            cout<<"-1"<<endl;
        }
        else {
            int k=1;
            for(int i=0;i<(n/2)+1;i++) {
                for(int j=0;j<n;j++) {
                    arr[i][j]=k;
                    k+=2;
                }
            }
            k=2;
            if(n%2) {
                
                for(int i=n/2;i<n;i++) {
                    for(int j=0;j<n;j++) {
                        if(i==n/2&&j<=n/2){

                        }
                        else{
                            arr[i][j]=k;
                            k+=2;
                        }                    
                    }
                }
            }
            else {
                for(int i=(n/2);i<n;i++) {
                    for(int j=0;j<n;j++) {
                        arr[i][j]=k;
                        k+=2;
                    }
                }
            }
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    cout<<arr[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        
    }
}