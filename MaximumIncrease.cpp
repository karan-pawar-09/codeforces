#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    long arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int maxi=0;
    int count=0;
    for(int i=0;i<n-1;i++) {

        if(arr[i]<arr[i+1])
        {
            count++;
        }
        else if(arr[i]>=arr[i+1])
        {
            maxi = max(maxi,count);
            count=0;
        }
    }
    maxi = max(maxi,count);
    cout<<maxi+1;
}
