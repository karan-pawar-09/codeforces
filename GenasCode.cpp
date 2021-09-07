#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<string> arr(n);
    string p;
    int zeros=0;
    int ace=0;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        if(((arr[i].size()==1)&(arr[i][0]=='0'))) {
            ace++;
            break;
        }
        else{
       // if(((arr[i].size()>1)&(arr[i].back()!=0))||((arr[i].size()==1)&(arr[i][0]!=1))) {
        if(arr[i].size()>=1){
            if(arr[i].size()==1){
                if(arr[i][0]!=1) {
                    p=arr[i];
                }
            }
            else{
                if(arr[i].back()!=0) {
                    p=arr[i];
                }
            }
        
        }

        if(arr[i].size()>=1){
            cout<<"  k   ";
            zeros+=(arr[i].size()-1);
        }
        }
    }
    if(ace==0){
    cout<<p;
    for(int i=0;i<zeros;i++) {
        cout<<"0";
    }
    }
    else{
        cout<<"0";
    }
}