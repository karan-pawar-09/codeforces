#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        vector<long> arr;
        for(int i=0;i<n;i++) {
            int ss;
            cin>>ss;
            arr.push_back(ss);
        }
        int ar[n];
        for(int i=0;i<n;i++){
            if(arr[i]<0){
                ar[i]=-1;
            }
            else {
                ar[i]=1;
            }
        }
        long long sump=0;
        long long sumn=0;
        int i=0;
          
        while(i<n) {
             int j=i;
             long  m;
             while((ar[i]==ar[j])&&j<n) {
                 m=arr[i];
                 if(arr[j]>m){
                     m=arr[j];
                 }                
                j++;
             }
             if(m>0){
                 sump+=m;
             }
             else{
                 sumn+=m;
             }
            i=j;
        }
        cout<<sump+sumn<<endl;
    }
}