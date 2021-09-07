/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            string k;
            cin>>k;
            arr[i].push_back(k);
        }
        int flag=1;
        for(int i=0;i<n;i++){
            int a=0,b=n-1;
            while(a<b){
                if(arr[i][a]!=arr[i][b]){
                    flag=0;
                }
                a++;
                b--;
            }
        }
        
   /*     if(flag!=0) {
        for(int j=0;j=n;j++){
            for(int i=0;i<=n/2;i++){
                if(arr[i][j]!=arr[i][n-1-j]){
                    flag=0;
                    break;
                }
            }
        }
        }
        */

        if(flag==1) {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}