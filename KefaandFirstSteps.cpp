#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    long arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int final_max=1;
    int maxi=1;
    for(int i=1;i<n;i++) {        
        if(arr[i]>=arr[i-1]) {
            maxi++;
        }
        else{
            maxi=1;
        }
        final_max=max(maxi,final_max);
    }
    cout<<final_max;
}