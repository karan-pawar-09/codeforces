#include<bits/stdc++.h>
using namespace std;
int main() {
    long n;
    cin>>n;
    vector<long> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    long cur=0;
    long maxi=0;
    for(int i=0;i<n-1;i++) {
        if(arr[i+1]%arr[i]==0) {
            cur++;
        }
        else{
            cur=0;
        }
        maxi=max(cur,maxi);
    }
    cout<<maxi+1;
}