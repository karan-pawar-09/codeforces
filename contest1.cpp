#include<bits/stdc++.h>
using namespace std;


int main() {
    int a;
    cin>>a;
    vector<string> arr(3*a);
    for(int i=0;i<(3*a);i++){
        cin>>arr[i];
    }

    int t=0;
    while(a--){
            int z=1;
        for(int i=0;i<arr[t].size();i++){
            if(arr[t+1][i]!=arr[t][i]){

                if((arr[t+2][i]!=arr[t][i])&&(arr[t+2][i]!=arr[t+1][i])){
                    z=0;
                    break;
                }
                else{
                    continue;
                }
            }
            else{
                if(arr[t+1][i]!=arr[t+2][i]){
                    z=0;
                    break;
                }
                else{
                    continue;
                }
            }
        }
        if(z==1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        t+=3;
    }
}
