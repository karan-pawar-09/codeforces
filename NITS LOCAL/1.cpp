#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<long> arr(n);
    long long sum=0;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
       
    }
    for(int i=0;i<n;i++) {
         sum+=arr[i];
    }
    cout<<sum;
}