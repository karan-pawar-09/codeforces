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
        char arr[n][n];
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cin>>arr[i][j];
            }
        }
        if(arr[0][1]==arr[1][0]) {
            if(arr[n-1][n-2]==arr[n-2][n-1]){
                if(arr[n-1][n-2]==arr[0][1]) {
                    cout<<"2"<<"\n"<<"1 2"<<endl<<"2 1"<<endl;
                }
                else{
                    cout<<"0"<<endl;
                }
            }
            else{
                if(arr[n-1][n-2]==arr[0][1]) {
                    cout<<"1"<<"\n"<<n<<" "<<n-1<<endl;
                }
                else{
                    cout<<"1"<<"\n"<<n-1<<" "<<n<<endl;
                }
            }
        }
        else {
            if(arr[n-1][n-2]==arr[n-2][n-1]){
                if(arr[n-1][n-2]==arr[0][1]) {
                    cout<<"1"<<"\n"<<"1 2"<<endl;
                }
                else{
                    cout<<"1"<<"\n"<<"2 1"<<endl;
                }
            }
            else{
                if(arr[n-1][n-2]==arr[0][1]) {
                    cout<<"2"<<"\n"<<"1 2"<<endl<<n-1<<" "<<n<<endl;
                }
                else{
                    cout<<"2"<<"\n"<<"1 2"<<endl<<n<<" "<<n-1<<endl;
                }
            }
        }
    }
}