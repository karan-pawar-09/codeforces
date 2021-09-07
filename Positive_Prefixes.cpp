#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int k,n;
        cin>>n>>k;
        vector<int>arr(n,0);
        int pos=(n+1)/2;
        if(n%2) {
            for(int i=0;i<n;i++) {
                if(i&1) {
                    arr[i]=-(i+1);
                }
                else {
                    arr[i]=(i+1);
                }
            }
        }
        else {
            for(int i=0;i<n;i++){
                if(i&1) {
                    arr[i]=(i+1);
                }
                else {
                    arr[i]=-(i+1);
                }
            }
        }
        
        int i=n-1;        
    
            while(k>pos) {
                if(arr[i]<0) {
                    arr[i]=-arr[i];
                    pos++;
                }
                i--;
            }
       
        
            while(pos>k) {
                if(arr[i]>0) {
                    arr[i]=-arr[i];
                    pos--;
                }
                i--;
            }

        for(int i=0;i<n;i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}