#include<bits/stdc++.h>
using namespace std;
int main() {
    long long t;
    cin>>t;
    while(t--) {
        long long n;
        cin>>n;
        vector<long> arr;
        for(long long i=0;i<n;i++) {
            long long ss;
            cin>>ss;
            arr.push_back(ss);
        }
        long long ar[n];
        long long a=0;
        long long b=0;
        for(long long i=0;i<n;i++){
            if(arr[i]<0){
                ar[i]=-1;
                b++;
            }
            else {
                ar[i]=1;
                a++;
            }
        }
     
        
        long long sump=0;
        long long sumn=0;
        long long i=0;
          
        while(i<n) {
             long long j=i;
             long long m;
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